#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int answer = -1;

    void dfs(int node, vector<int> &edges, unordered_map<int, int> &dist, vector<bool> &visited)
    {
        visited[node] = true;

        if (edges[node] != -1 && !visited[edges[node]])
        {
            dist[edges[node]] = dist[node] + 1;
            dfs(edges[node], edges, dist, visited);
        }
        else if (edges[node] != -1 && dist.count(edges[node]))
        {
            answer = max(answer, dist[node] - dist[edges[node]] + 1);
        }
    }

    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<bool> v(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!v[i])
            {
                unordered_map<int, int> d;
                d[i] = 1;
                dfs(i, edges, d, v);
            }
        }
        return answer;
    }
};

int main()
{

    return 0;
}