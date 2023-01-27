#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
using namespace std;

#define el << '\n'
#define ws << ' '

// for every city we will store the all possible combinations to reach that city from src
// then we will anaylze all route for dest city for the optimal ans
/*Algorithm
We calculated every k and its minimum price for every city node starting from src
We then find the least ans from the soln list we genereated with the destination city as input
 */
struct path
{
    int to;
    int price;
};
void bfs(map<int, vector<path>> &flights, map<int, map<int, pair<int, bool>>> &soln, int src, int n, int maxStop)
{
    queue<int> q;
    q.push(src);

    soln[src][0] = {0, 0};
    // k ,price
    while (!q.empty())
    {
        int curCity = q.front();
        vector<path> destination = flights[curCity];

        for (auto &&k : soln[curCity])
        {
            // cout << '\t' << k.first ws << (*k.second.begin()).first ws << (*k.second.begin()).second el;
            int k_here = k.first;
            if (k.second.second == false)
            {
                for (auto &&dest : destination)
                {
                    if (k_here + 1 <= maxStop && dest.to != src)
                    {
                        map<int, pair<int, bool>>::iterator it = soln[dest.to].find(k_here + 1);
                        if (it != soln[dest.to].end())
                        {
                            if ((it->second.first) > k.second.first + dest.price)
                            {
                                (it->second) = {k.second.first + dest.price, 0};
                                q.push(dest.to);
                            }
                        }
                        else
                        {
                            soln[dest.to][k_here + 1] = {k.second.first + dest.price, 0};
                            q.push(dest.to);
                        }
                    }
                }
                k.second.second = true;
            }
        }
        q.pop();
    }

    // Prinitng visited
    // cout << "Non Visited Cities: ";
    // for (auto &&i : visited)
    //     if (i.second == false)
    //         cout << i.first ws;
    // cout el;
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    map<int, vector<path>> m;
    map<int, map<int, pair<int, bool>>> soln;
    // DestinationCity->k->Price->Visited
    for (int i = 0; i < flights.size(); i++)
    {
        m[flights[i][0]].push_back({flights[i][1], flights[i][2]});
    }

    // Print m
    // cout << "m:\n";
    // for (auto &&i : m)
    // {
    //     cout << i.first el;
    //     for (auto &j : i.second)
    //         cout << '\t' << j.to ws << j.price el;
    // }

    bfs(m, soln, src, n, k + 1);

    int finalans = INT_MAX;
    for (auto &&k : soln[dst])
        finalans = min(k.second.first, finalans);

    // // Print soln
    // cout << "Soln\n";
    // for (auto &&i : soln)
    // {
    //     cout << i.first el;
    //     for (auto &j : i.second)
    //     {
    //         cout << '\t' << j.first ws << j.second.first ws << j.second.second el;
    //     }
    // }

    return finalans == INT_MAX ? -1 : finalans;
}
int main()
{
    vector<vector<int>> flights = {{0, 1, 5}, {1, 2, 5}, {0, 3, 2}, {3, 1, 2}, {1, 4, 1}, {4, 2, 1}};
    cout << findCheapestPrice(5, flights, 0, 2, 2) el;
    return 0;
}