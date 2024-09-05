#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

class City
{
public:
    string name;
    int goods;
    int tax;

    City()
    {
        name = "";
        goods = 0;
        tax = 0;
    }
    City(string n, int g, int t) : name(n), goods(g), tax(t) {}
};
unordered_map<string, City> Cities;

bool compareCities(const string &c1, const string &c2)
{
    City city1 = Cities[c1];
    City city2 = Cities[c2];
    if (city1.goods != city2.goods)
    {
        return city1.goods > city2.goods;
    }
    else if (city1.tax != city2.tax)
    {
        return city1.tax < city2.tax;
    }
    else
    {
        return city1.name < city2.name;
    }
}

void solve(string startCity, map<string, vector<string>> &m, set<string> &visited, vector<string> &path)
{
    // cout << startCity << '\n';
    path.push_back(startCity);
    visited.insert(startCity);

    for (auto &i : m[startCity])
    {
        // if (visited.find(i) == visited.end())
        // {
        solve(i, m, visited, path);
        path.push_back(startCity);
        // }
    }
}

int main()
{
    int n;
    cin >> n;

    Cities.clear();
    map<string, vector<string>> graph;

    string startCity;
    string city1, city2;
    int goods, tax;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> city1 >> city2 >> goods >> tax;

        if (i == 0)
            startCity = city1;

        if (Cities.find(city1) == Cities.end())
            Cities[city1] = City(city1, 0, 0);
        if (Cities.find(city2) == Cities.end())
            Cities[city2] = City(city2, goods, tax);

        graph[city1].push_back(city2);
    }

    if (n == 1)
    {
        std::cout << startCity << '\n'
                  << 0;
        return 0;
    }
    set<string> visited;
    vector<string> path;
    long long totalCost = 0;

    for (auto &i : graph)
        sort(i.second.begin(), i.second.end(), compareCities);

    // for (auto &i : graph)
    // {
    //     cout << i.first << ": ";
    //     for (auto &j : i.second)
    //     {
    //         cout << Cities[j].name << " ";
    //     }
    //     cout << '\n';
    // }

    solve(startCity, graph, visited, path);
    for (auto &i : path)
    {
        totalCost += Cities[i].tax;
    }

    for (unsigned int i = 0; i < path.size() - 1; i++)
    {
        cout << path[i] << "-";
    }
    cout << path[path.size() - 1];
    cout << '\n'
         << totalCost;

    return 0;
}
