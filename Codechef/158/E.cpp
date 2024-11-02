#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_RUN
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
#define input(vec, n)           \
    for (int i = 0; i < n; i++) \
        std::cin >> vec[i];

#define el << endl;
#define ws << " ";

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
constexpr unsigned int mod = 1e9 + 7;

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vector<vector<int>> tree(n + 1);

    vi in(n + 1, 0);
    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        in[u]++;
        in[v]++;
    }

    int k = *max_element(all(in));
    cout << k el;

    debug(in);

    set<pair<int, int>> pairs;
    for (int i = 0; i < k; i++)
    {
        set<int> visited;
        queue<int> q;
        q.push(1);
        visited.insert(1);
        vi ans(n + 1);
        for (int i = 1; i <= n; i++)
        {
            ans[i] = i;
        }

        set<int> vis;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &child : tree[node])
            {
                if (in[node] > 0 && in[child] > 0 && pairs.count({min(node, child), max(node, child)}) == 0)
                {
                    if (vis.count(node) == 0 && vis.count(child) == 0)
                    {
                        debug(node, child);
                        ans[child] = ans[node];
                        pairs.insert({min(node, child), max(node, child)});
                        in[node]--;
                        in[child]--;
                        vis.insert(node);
                        vis.insert(child);
                    }
                }
                if (visited.find(child) == visited.end())
                {
                    visited.insert(child);
                    q.push(child);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] ws;
        }
        cout el;
    }
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}