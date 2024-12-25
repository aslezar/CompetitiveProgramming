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
typedef pair<int, int> pii;
constexpr unsigned int mod = 1e9 + 7;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {

        parent.resize(n + 1);

        for (size_t i = 0; i < parent.size(); i++)
            parent[i] = i;

        size.resize(n + 1, 1);
    }
    int findUltimateParent(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = findUltimateParent(parent[u]);
    }
    void unionBySize(int u, int v)
    {
        int p_u = findUltimateParent(u);
        int p_v = findUltimateParent(v);
        if (p_u == p_v)
            return;
        if (size[p_v] > size[p_u])
        {
            // join u to v
            parent[p_u] = p_v;
            size[p_v] += size[p_u];
        }
        else
        {
            // join v to u
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        }
    }
    int getSize(int u)
    {
        return size[findUltimateParent(u)];
    }
};

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);

    DisjointSet ds(n + 1);
    for (int i = 0; i < n; i++)
    {
        ds.unionBySize(v[i], v[v[i] - 1]);
    }

    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[ds.findUltimateParent(i + 1)] = ds.getSize(i + 1);
    }
    priority_queue<int, vector<int>, greater<int>> sizes;
    for (auto [k, v] : m)
    {   
        sizes.push(v);
    }
    debug(sizes);
    if (sizes.size() == 1)
    {
        cout << 0 el;
        return;
    }
    int cost = 0;
    while (sizes.size() > 1)
    {
        int a = sizes.top();
        sizes.pop();
        int b = sizes.top();
        sizes.pop();
        cost += a + b;
        sizes.push(a + b);
    }
    cout << cost el;
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