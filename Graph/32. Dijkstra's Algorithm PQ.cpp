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
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // T.C. E*log(V)
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);

        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            auto top = pq.top();
            int distance = top.first;
            int node = top.second;
            pq.pop();

            for (auto &it : adj[node])
            {
                int adjNode = it[0];
                int edgeWg = it[1];

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
    Solution s;

    // cout << s.checkTwoChessboards("a1", "b2") << endl;
    cout << endl;

    return 0;
}

#endif