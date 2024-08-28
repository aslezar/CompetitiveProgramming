#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, x, k;
    cin >> n >> x >> k;
    map<long long, long long> m;
    long long t = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> t;
        m[t]++;
    }
    vector<long long> h, ones;
    long long one = 0;
    for (auto &i : m)
    {
        // cout << i.first << ' ' << i.second << '\n';
        h.push_back(i.first);
        if (i.second == 1)
            one++;
        ones.push_back(one);
    }
    ones.push_back(0);
    // cout << endl;

    // cout << h.end() - h.begin() << '\n';

    long long ans = 0;
    auto it_x = lower_bound(h.begin(), h.end(), x);
    ans = it_x - h.begin();

    // cout << "*it_x " << *it_x << endl;

    auto it_xk = lower_bound(h.begin(), h.end(), x * k);
    ans = max(ans, (long long)(it_xk - h.begin()));

    for (long long i = it_x - h.begin() - 1; i >= 0; i--)
    {
        auto it_ck = lower_bound(h.begin(), h.end(), h[i] * k);
        // cout << "it_ck " << *it_ck << '\n';
        long long curAns = it_ck - h.begin();
        curAns += (long long)(it_x - next(h.begin(), i));

        long long minIs = min(it_x - h.begin(), it_ck - h.begin());
        curAns -= (ones[minIs - 1] - (i > 0 ? ones[i - 1] : 0));

        ans = max(ans, curAns);
    }

    cout << ans << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t != 0)
    {
        solve();
        t--;
    }
    return 0;
}