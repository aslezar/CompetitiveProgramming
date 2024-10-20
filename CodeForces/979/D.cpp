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

    ll q = 0;
    cin >> q;

    vi v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    string s;
    cin >> s;
    s = '0' + s;

    DisjointSet d(n + 1);
    for (int i = 1; i <= n; i++)
    {
        // d.unionByRank(v[i], i);
        d.unionByRank(min(v[i], i), max(v[i], i));
    }

    map<int, int> linksNeeded;
    for (int i = 1; i < n; i++)
    {
        if (d.findUltimateParent(i) != i)
        {
            linksNeeded[i] = -1;
            linksNeeded[d.findUltimateParent(i)] = -1;
        }
    }
    // debug(linksNeeded);

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'L')
        {
            if (linksNeeded.count(i - 1))
                linksNeeded[i - 1]++;
        }
        else
        {
            if (linksNeeded.count(i))
                linksNeeded[i]++;
        }
    }

    int negative = 0;

    for (auto &i : linksNeeded)
    {
        if (i.second < 0)
            negative++;
    }

    // debug(linksNeeded);
    // debug(negative);

    int i = 0;
    for (int qq = 0; qq < q; qq++)
    {
        cin >> i;
        if (s[i] == 'R')
        {
            if (linksNeeded.count(i))
            {
                if (linksNeeded[i] == 0)
                    negative++;
                linksNeeded[i]--;
            }
            if (linksNeeded.count(i - 1))
            {
                if (linksNeeded[i - 1] < 0)
                    negative--;
                linksNeeded[i - 1]++;
            }
            s[i] = 'L';
        }
        else
        {
            if (linksNeeded.count(i - 1))
            {
                if (linksNeeded[i - 1] == 0)
                    negative++;
                linksNeeded[i - 1]--;
            }
            if (linksNeeded.count(i))
            {
                if (linksNeeded[i] < 0)
                    negative--;
                linksNeeded[i]++;
            }
            s[i] = 'R';
        }
        if (negative <= 0)
            cout << "Yes\n";
        else
            cout << "No\n";
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