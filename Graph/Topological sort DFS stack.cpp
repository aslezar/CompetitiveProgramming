#ifdef LOCAL_RUN

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

// #define int long long
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
    void dfs(vi adj[], int node, vi &ans, vi &vis)
    {
        vis[node] = 1;
        for (auto &i : adj[node])
        {
            if (!vis[i])
            {
                dfs(adj, i, ans, vis);
            }
        }
        ans.push_back(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vi ans;
        vi vis(V);
        FOR(i, 0, V - 1)
        {
            if (!vis[i])
            {
                dfs(adj, i, ans, vis);
            }
        }
        reverse(all(ans));
        return ans;
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