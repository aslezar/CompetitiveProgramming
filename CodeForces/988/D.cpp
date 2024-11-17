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
    int n, m, l;
    cin >> n >> m >> l;

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a] = b - a + 2;
    }
    multimap<int, int> powers;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        powers.insert({a, b});
    }

    priority_queue<int> pq;
    int ans = 0;
    auto it = powers.begin();
    int curPower = 1;
    for (auto &i : mp)
    {
        while (it != powers.end() && it->first < i.first)
        {
            pq.push(it->second);
            it++;
        }
        while (curPower < i.second)
        {
            if (pq.empty())
            {
                cout << -1 el;
                return;
            }
            curPower += pq.top();
            ans++;
            pq.pop();
        }
    }
    cout << ans el;
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