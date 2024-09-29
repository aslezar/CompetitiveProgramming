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

    ll m = 0;
    cin >> m;

    vi v(n);
    input(v, n);

    map<int, vector<int>> height;

    for (int i = 0; i < n; i++)
    {
        int step = 0;
        int curHeight = v[i];

        while (curHeight > 0)
        {
            auto it = height.find(curHeight);
            if (it == height.end())
            {
                height[curHeight] = vector<int>(n, -1);
                it = height.find(curHeight);
            }
            it->second[i] = step;
            curHeight /= 2;
            step++;
        }
    }
    debug(height);

    auto prev = height.begin();
    auto cur = next(prev);
    auto nxt = next(cur);

    // debug(prev->first, cur->first, nxt->first);

    while (cur != height.end())
    {
        for (int i = 0; i < cur->second.size(); i++)
        {
            if (cur->second[i] != -1)
                continue;

            ll x = LLONG_MAX;
            ll z = LLONG_MAX;
            if (prev->second[i] != -1)
            {
                x = prev->second[i] + (cur->first - prev->first);
            }
            if (nxt != height.end() && nxt->second[i] != -1)
            {
                z = nxt->second[i] + (nxt->first - cur->first);
            }
            cur->second[i] = min(x, z);
        }
        prev++;
        cur++;
        nxt++;
    }

    // debug(height);

    int ans = LLONG_MAX;
    for (auto &i : height)
    {
        if (i.first == 0)
            continue;
        sorta(i.second);
        ll x = accumulate(i.second.begin(), i.second.end() - m, 0ll);
        ans = min(ans, x);
    }

    cout << ans el;

    // int ans = INT_MAX;

    // // try to make all heigths equal to v[i]
    // // operation allowed
    // // increase by 1
    // // decrease by 1
    // // floor of h/2

    // // for (int i = 1; i <= v.back(); i++)
    // // use middle value
    // int maxheight = sqrt(v.back());
    // for (int i = 1; i <= v.back() / 2; i++)
    // {

    //     int reqHeight = i;

    //     // vector<int> operations;
    //     // min heap
    //     priority_queue<int> operations;
    //     for (int j = 0; j < n; j++)
    //     {
    //         int opr = INT_MAX;
    //         int step = 0;
    //         int val = v[j];

    //         // for 5, optimal values for 25-> 12 6 3 1, we need to consider only 6 and 3
    //         while (val > 0)
    //         {
    //             opr = min(opr, step + abs(val - reqHeight));
    //             val /= 2;
    //             step++;
    //         }
    //         operations.push(opr);
    //         if (operations.size() > n - m)
    //         {
    //             operations.pop();
    //         }
    //     }
    //     // take n-m small values from operations
    //     int sum = 0;
    //     debug(i, operations);
    //     while (!operations.empty())
    //     {
    //         sum += operations.top();
    //         operations.pop();
    //     }
    //     ans = min(ans, sum);
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