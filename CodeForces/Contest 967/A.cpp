#include <bits/stdc++.h>
using namespace std;

#define ll long long
const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        vector<int> nums(n + 1);
        int t;
        for (int i = 0; i < n; i++)
        {
            cin >> t;
            nums[t]++;
        }
        int maxFreq = 0;
        for (int i = 0; i <= n; i++)
        {
            maxFreq = max(maxFreq, nums[i]);
        }
        cout << n - maxFreq << endl;
    }
    return 0;
}