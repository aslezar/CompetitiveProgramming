#include <bits/stdc++.h>
using namespace std;

#define ll long long
const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

ll giveVal(vector<pair<int, int>> &v, int index, int k)
{
    ll val = v[index].first;
    int n = v.size();
    if (n & 1)
    {
        int medianIdx1 = n / 2;
        int medianIdx2 = 0;
        if (index < medianIdx1)
        {
            medianIdx2 = medianIdx1 + 1;
        }
        else if (index > medianIdx1)
        {
            medianIdx2 = medianIdx1 - 1;
        }
        else
        {
            medianIdx1 = index - 1;
            medianIdx2 = index + 1;
        }
        int med = double(v[medianIdx1].first + v[medianIdx2].first + 1) / 2;
        val += med;
        if (v[index].second == 1)
        {

            val += k;
        }
        else if (v[medianIdx1].second == 1 || v[medianIdx2].second == 1)
        {
            val += (k / 2);
        }
    }
    else
    {
        // even size, after deleting one becomes odd
        int medianIndex = (n - 1) / 2;
        if (index <= medianIndex)
            medianIndex++;
        val += v[medianIndex].first;
        if (v[index].second == 1 || v[medianIndex].second == 1)
            val += k;
    }

    return val;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i].first;
        for (int i = 0; i < n; i++)
            cin >> v[i].second;

        sort(v.begin(), v.end());

        ll ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, giveVal(v, i, k));
        }
        cout << ans << '\n';
    }
    return 0;
}