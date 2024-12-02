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

void solve(vi &list1, vi &list2)
{
    assert(list1.size() == list2.size());
    sorta(list1);
    sorta(list2);

    int ans = 0;
    for (size_t i = 0; i < list1.size(); i++)
    {
        ans += abs(list1[i] - list2[i]);
    }
    cout << ans el;
}

void solve2(vi &list1, vi &list2)
{
    unordered_map<int, int> f;
    for (auto &i : list2)
    {
        f[i]++;
    }
    int ans = 0;
    for (size_t i = 0; i < list1.size(); i++)
    {
        ans += (list1[i] * f[list1[i]]);
    }
    cout << ans el;
}

int32_t main()
{
    freopen("1.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    vi list1, list2;
    int a, b;
    while (cin >> a >> b)
    {
        list1.push_back(a);
        list2.push_back(b);
    }
    solve(list1, list2);
    solve2(list1, list2);
    return 0;
}