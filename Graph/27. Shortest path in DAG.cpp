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
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {

        vector<vector<pair<int, int>>> adj(N);

        for (int i = 0; i < edges.size(); i++)
        {
            int &u = edges[i][0];
            int &v = edges[i][1];
            int &w = edges[i][2];

            adj[u].push_back({v, w});
        }

        vector<int> in(N);
        for (int i = 0; i < N; i++)
        {
            for (auto &node : adj[i])
            {
                in[node.first]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            topo.push_back(front);

            for (auto &i : adj[front])
            {
                in[i.first]--;
                if (in[i.first] == 0)
                {
                    q.push(i.first);
                }
            }
        }
        reverse(topo.begin(), topo.end());

        vector<int> dist(N, 1e9);
        dist[0] = 0;

        while (!topo.empty())
        {
            auto top = topo.back();
            topo.pop_back();

            for (auto &i : adj[top])
            {
                dist[i.first] = min(dist[i.first], dist[top] + i.second);
            }
        }

        for (auto &i : dist)
            if (i == 1e9)
                i = -1;

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