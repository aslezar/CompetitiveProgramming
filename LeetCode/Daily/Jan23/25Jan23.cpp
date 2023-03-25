#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define el << '\n'
#define ws << ' '

void bfs(vector<int> &edges, vector<int> &dist, int startNode)
{
    queue<int> q;
    q.push(startNode);
    vector<bool> visited(edges.size(), false);
    // visited[0] = 1;
    dist[startNode] = 0;
    while (!q.empty())
    {
        int curNode = q.front();
        if (!visited[curNode] && edges[curNode] != -1 && !visited[edges[curNode]])
        {
            visited[curNode] = true;
            dist[edges[curNode]] = dist[curNode] + 1;
            q.push(edges[curNode]);
        }
        q.pop();
    }
}

int closestMeetingNode(vector<int> &edges, int node1, int node2)
{
    vector<int> distance1(edges.size(), INT_MAX), distance2(edges.size(), INT_MAX);
    bfs(edges, distance1, node1);
    bfs(edges, distance2, node2);
    int minDistNode = -1; // Out ans
    int minDistTillNow = INT_MAX;
    for (int i = 0; i < edges.size(); i++)
    {
        if (minDistTillNow > max(distance1[i], distance2[i]))
        {
            minDistTillNow = max(distance1[i], distance2[i]);
            minDistNode = i;
        }
    }

    return minDistNode;
}
int main()
{
    vector<int> edge = {2, 2, 3, -1};
    cout << closestMeetingNode(edge, 0, 1) el;

    return 0;
}