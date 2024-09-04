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
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {

        vector<vector<int>> adj(N);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> dist(N, 1e9);
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            for (auto &i : adj[front])
            {
                if (dist[front] + 1 < dist[i])
                {
                    dist[i] = dist[front] + 1;
                    q.push(i);
                }
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