#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges,
                                         vector<vector<int>> &blueEdges)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &redEdge : redEdges)
        {
            adj[redEdge[0]].push_back({redEdge[1], 0});
        }
        for (auto &blueEdge : blueEdges)
        {
            adj[blueEdge[0]].push_back(make_pair(blueEdge[1], 1));
        }

        vector<int> ans(n, -1);
        vector<vector<bool>> visit(n, vector<bool>(2));
        queue<vector<int>> q;

        q.push({0, 0, -1});
        visit[0][1] = true;
        visit[0][0] = true;
        ans[0] = 0;

        while (!q.empty())
        {
            auto element = q.front();
            int node = element[0], steps = element[1], prevColor = element[2];
            q.pop();

            for (auto &i : adj[node])
            {
                if (!visit[i.first][i.second] && i.second != prevColor)
                {
                    visit[i.first][i.second] = true;
                    q.push({i.first, 1 + steps, i.second});
                    if (ans[i.first] == -1)
                        ans[i.first] = 1 + steps;
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}