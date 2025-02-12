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

void insert(map<int, unordered_map<int, pair<int, int>>> &m, int l, int r)
{
    int ele = r - l;
    if (ele & 1)
    {

        m[ele / 2].insert({l + (ele / 2), {l, r}});
        m[ele / 2].insert({l + (ele / 2) + 1, {l, r}});
    }
    else
    {
        m[ele / 2].insert({l + (ele / 2), {l, r}});
    }
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);

    if (n <= 2)
    {
        cout << "YES\n";
        return;
    }

    unordered_map<int, int> indexOf;
    for (int i = 0; i < n; i++)
    {
        indexOf[v[i]] = i;
    }
    debug(indexOf);

    // debug((indexOf[1] == 0 && indexOf[2] == n - 1));
    // debug((indexOf[1] == n - 1 && indexOf[2] == 0));
    // debug(((indexOf[1] == 0 && indexOf[2] == n - 1) || (indexOf[1] == n - 1 && indexOf[2] == 0)));

    if (!((indexOf[1] == 0 && indexOf[2] == n - 1) || (indexOf[1] == n - 1 && indexOf[2] == 0)))
    {
        debug("Here");
        cout << "NO\n";
        return;
    }

    // map<int, set<pair<int, int>>> m;
    map<int, unordered_map<int, pair<int, int>>> m;
    insert(m, 0, n - 1);
    // int ele = n - 1 - 0;
    // if (ele & 1)
    // {

    //     m[ele / 2].insert({ele / 2, {0, n - 1}});
    //     m[ele / 2].insert({ele / 2 + 1, {0, n - 1}});
    // }
    // else
    // {
    //     m[ele / 2].insert({ele / 2, {0, n - 1}});
    // }
    for (int i = 3; i <= n; i++)
    {
        int index = indexOf[i];
        debug(i);
        debug(m);

        auto find = m.rbegin()->second.find(index);

        if (find == m.rbegin()->second.end())
        {
            debug("Here2", i);
            cout << "NO\n";
            return;
        }
        auto p = find->second;
        m.rbegin()->second.erase(index);
        auto find1 = m.rbegin()->second.find(index + 1);
        if (find1 != m.rbegin()->second.end())
        {
            if (find1->second == p)
            {
                m.rbegin()->second.erase(index + 1);
            }
        }
        auto find2 = m.rbegin()->second.find(index - 1);
        if (find2 != m.rbegin()->second.end())
        {
            if (find2->second == p)
            {
                m.rbegin()->second.erase(index - 1);
            }
        }
        // m.rbegin()->second.erase(index + 1);
        // m.rbegin()->second.erase(index - 1);

        insert(m, p.first, index);
        insert(m, index, p.second);

        if (m.rbegin()->second.size() == 0)
        {
            m.erase(m.rbegin()->first);
        }

        if (m.rbegin()->first <= 1)
        {
            break;
        }
        // for (auto &p : m.rbegin()->second)
        // {
        //     int e = p.second - p.first;
        //     if (e & 1)
        //     {
        //         int i1 = p.first + e / 2;
        //         int i2 = p.first + e / 2 + 1;
        //         if (i1 == index || i2 == index)
        //         {
        //             find = true;
        //             m[(index - p.first) / 2].insert({p.first, index});
        //             m[(p.second - index) / 2].insert({index, p.second});
        //             m.rbegin()->second.erase(p);
        //             break;
        //         }
        //     }
        //     else
        //     {
        //         int i1 = p.first + e / 2;
        //         if (i1 == index)
        //         {
        //             find = true;
        //             m[(index - p.first) / 2].insert({p.first, index});
        //             m[(p.second - index) / 2].insert({index, p.second});
        //             m.rbegin()->second.erase(p);
        //             break;
        //         }
        //     }
        // }
    }
    debug(m);
    debug("Here3");
    cout << "YES\n";
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