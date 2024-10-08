#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.length();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        vector<vector<int>> count(n, vector<int>(26));
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        int answer = 0, nodesSeen = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            answer = max(answer, ++count[node][colors[node] - 'a']);
            nodesSeen++;

            for (auto &neighbor : adj[node])
            {
                for (int i = 0; i < 26; i++)
                    count[neighbor][i] = max(count[neighbor][i], count[node][i]);

                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        return nodesSeen < n ? -1 : answer;
    }
};
int main()
{

    return 0;
}