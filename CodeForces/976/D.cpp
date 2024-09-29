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

class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {

        parent.resize(n + 1);

        rank.resize(n + 1);
        for (size_t i = 0; i < parent.size(); i++)
            parent[i] = i;
    }
    int findUltimateParent(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = findUltimateParent(parent[u]);
    }
    // T.C. O(4*alpha) = O(1) alpha is the inverse ackermann function
    void unionByRank(int u, int v)
    {
        int p_u = findUltimateParent(u);
        int p_v = findUltimateParent(v);
        if (p_u == p_v)
            return;
        if (rank[p_v] > rank[p_u])
        {
            parent[p_u] = p_v;
        }
        else if (rank[p_u] > rank[p_v])
        {
            parent[p_v] = p_u;
        }
        else
        {
            parent[p_v] = p_u;
            rank[p_u]++;
        }
    }
};

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    ll m = 0;
    cin >> m;

    DisjointSet ds(n + 1);

    ll a, d, k;

    vector<vector<pair<int, int>>> t(11);
    for (int mm = 0; mm < m; mm++)
    {
        cin >> a >> d >> k;
        ll min_no = a;
        ll max_no = a + k * d;

        bool simIntervalFind = false;
        for (int i = 0; i < t[d].size(); i++)
        {
            auto min_pair = min(t[d][i], {min_no, max_no});
            auto max_pair = max(t[d][i], {min_no, max_no});
            if (min_pair.second >= max_pair.first)
            {
                if (abs(min_pair.first - max_pair.first) % d != 0)
                {
                    continue;
                }

                t[d][i] = {min(min_pair.first, max_pair.first), max(min_pair.second, max_pair.second)};
                simIntervalFind = true;
                break;
            }
        }
        if (simIntervalFind == false)
        {
            t[d].push_back({min_no, max_no});
        }
    }

    // debug(t);

    for (int i = 1; i <= 10; i++)
    {

        for (auto &interval : t[i])
        {
            int l = interval.first;
            int r = interval.second;
            for (int j = l; j < r; j += i)
            {
                ds.unionByRank(j, j + i);
            }
        }
    }

    // count the number of connected components
    unordered_set<int> components;
    for (int i = 1; i <= n; i++)
    {
        components.insert(ds.findUltimateParent(i));
    }
    cout << components.size() el;

    // int ans = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (ds.findUltimateParent(i) == i)
    //     {
    //         ans++;
    //     }
    // }
    // cout << ans el;
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