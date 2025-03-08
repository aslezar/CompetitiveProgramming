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

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);

    vi pSum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pSum[i + 1] = v[i] + pSum[i];
    }

    vi left(n, 0), right(n, 0);

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && v[s.top()] > v[i])
        {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while (!s.empty())
    {
        s.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && v[s.top()] > v[i])
        {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    debug(left);
    debug(right);
    debug(pSum);

    vector<pii> intervals;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = pSum[right[i] - 1 + 1] - pSum[left[i] + 1];

        int range = right[i] - left[i] - 1;
        int cost = (v[i] * range) + range;

        debug(i, curr, range, cost);
        // cost += min(curr, range);
        if (cost < curr)
        {
            intervals.push_back({left[i] + 1, right[i] - 1});
            ans += range;
        }
    }

    sorta(intervals);

    auto overlap = [](pii a, pii b) -> bool
    {
        if (a.first > b.first)
        {
            swap(a, b);
        }
        return b.second <= a.second;
    };

    vector<pii> fI;
    for (auto &i : intervals)
    {
        if (fI.empty() || !overlap(i, fI.back()))
        {
            fI.push_back(i);
        }
        else
        {
            fI.back().first = min(fI.back().first, i.first);
            fI.back().second = max(fI.back().second, i.second);
        }
    }

    for (auto i : fI)
    {
        int mn = *min_element(v.begin() + i.first, v.begin() + i.second);
        for (int j = i.first; j <= i.second; j++)
        {
            v[j] = mn;
        }
    }

    for (auto &i : v)
    {
        ans += i;
    }
    debug(v, ans);
    cout << ans << '\n';
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

// 5 2 7 10 2
// 9
// 5

// 0-1
// 1-2

// 7+2 = 9
// 4+1 = 5

// 17
// 14 +1

// 1-3

// 2 2 2 2 2 10+3

/*

2 3 7 10 1

*/

/*

2 2

*/