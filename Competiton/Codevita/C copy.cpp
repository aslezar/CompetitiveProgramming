#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void dfs(string city, map<string, map<string, pair<int, int>>> &graph, vector<string> &route)
{
    route.push_back(city);
    for (auto n : graph[city])
    {
        dfs(n.first, graph, route);
        route.push_back(city);
    }
}

pair<vector<string>, int> pick_up_service(int N, string start, vector<tuple<string, string, int, int>> &connections)
{
    map<string, map<string, pair<int, int>>> graph;
    map<string, int> taxes;

    for (int i = 0; i < N - 1; ++i)
    {
        string city1, city2;
        int goods, tax;
        tie(city1, city2, goods, tax) = connections[i];
        graph[city1][city2] = make_pair(goods, tax);
        taxes[city2] = tax;
    }

    vector<string> route;
    dfs(start, graph, route);

    int total_tax = 0;
    for (size_t i = 1; i < route.size(); ++i)
    {
        total_tax += taxes[route[i]];
    }

    return make_pair(route, total_tax);
}

int main()
{
    int N;
    cin >> N;

    vector<tuple<string, string, int, int>> cons;

    for (int i = 0; i < N - 1; ++i)
    {
        string l, city1, city2;
        int goods, tax;
        // cin >> l;
        // istringstream iss(l);
        cin >> city1 >> city2 >> goods >> tax;
        cons.push_back(make_tuple(city1, city2, goods, tax));
    }

    auto result = pick_up_service(N, get<0>(cons[0]), cons);

    for (unsigned int i = 0; i < result.first.size() - 1; i++)
    {
        cout << result.first[i] << "-";
    }
    cout << result.first[result.first.size() - 1];
    cout << '\n'
         << result.second;

    return 0;
}
