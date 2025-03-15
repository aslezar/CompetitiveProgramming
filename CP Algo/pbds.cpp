#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_RUN
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, pair<int, int>, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
// ordered_set o_set;
// o_set.insert(5);
// o_set.find_by_order(1)
// o_set.order_of_key(5)

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

void solve([[maybe_unused]] ll &_case_no)
{
    ordered_set o;
    o.insert(1);
    o.insert(2);
    o.insert(3);
    o.insert(4);
    o.insert(5);

    cout << *(o.find_by_order(3)) << '\n';
    cout << o.order_of_key(3) << '\n';

    ordered_map m;
    m.insert({1, {10, 21}});
    m.insert({2, {11, 22}});
    m.insert({3, {12, 23}});
    m.insert({4, {13, 24}});
    m.insert({5, {14, 25}});

    for (auto &i : m)
    {
        debug(i);
    }

    m[6] = {15, 26};

    debug((*m.find_by_order(5)));
    cout << m.order_of_key(3) << '\n';
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    // cin >> t;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}