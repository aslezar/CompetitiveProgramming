#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int negative = 0;
    int minValue = INT_MAX;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
            negative++;
        minValue = min(minValue, abs(a[i]));
        sum += abs(a[i]);
    }
    if (negative % 2 == 0)
    {
        // print all positive sum
        cout << sum << endl;
    }
    else
    {
        cout << sum - (2 * minValue) << endl;
    }
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