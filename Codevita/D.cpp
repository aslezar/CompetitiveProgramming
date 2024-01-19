#include <iostream>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

int manhattanDistance(pair<int, int> &c1, pair<int, int> &c2)
{
    return abs(c1.first - c2.first) + abs(c1.second - c2.second);
}

int main()
{
    map<string, pair<int, int>> person;
    map<int, pair<int, int>> vechile;
    int n = 0;
    int m = 0;
    long long ans = 0;
    string personName;
    int x, y;

    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> personName;
        cin >> x >> y;
        person[personName] = make_pair(x, y);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> personName;
        cin >> x >> y;
        vechile[stoi(personName.substr(1))] = make_pair(x, y);
    }

    for (auto &i : person)
    {
        int d = INT_MAX;
        int v = -1;
        for (auto &j : vechile)
        {
            int dist = manhattanDistance(i.second, j.second);
            if (dist < d)
            {
                d = dist;
                v = j.first;
            }
        }
        ans += d;
        vechile.erase(v);
    }
    std::cout << ans;
}