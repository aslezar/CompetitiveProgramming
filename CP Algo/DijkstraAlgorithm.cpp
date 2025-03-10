/*
    Djikstra's Algorithm
    It is used to find the shortest path for all nodes to all nodes
    It can not be used for graph having negative weight edges
    It is greedy algorithm
    It uses priority queue to get the minimum distance node

    we start from the source node
    if we find a adj node from current node that can be reach in less distance
    then we update the distance of the adj node and push the adj node in the priority queue for further processing

    // Time Complexity: O(E*log(V))
*/

#ifdef LOCAL_RUN

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))
#define set_bits __builtin_popcount

#define F first
#define S second
#define PB push_back
#define gcd __gcd
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

constexpr unsigned int mod = 1e9 + 7;
constexpr unsigned int maxn = 1e5 + 4;
constexpr float EPS = numeric_limits<float>::epsilon();
constexpr ll INF = numeric_limits<ll>::max();

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<pii>> adj, int src)
    {
        // T.C. E*log(V)

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V + 1, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto top = pq.top();
            int distance = top.first;
            int node = top.second;
            pq.pop();

            if (dist[node] < distance)
                continue;

            for (auto &it : adj[node])
            {
                int adjNode = it.first;
                int edgeWg = it.second;

                if (distance + edgeWg < dist[adjNode])
                {
                    dist[adjNode] = distance + edgeWg;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    return 0;
}

#endif