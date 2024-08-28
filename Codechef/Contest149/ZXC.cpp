#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long dup_pair = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dup_pair++;
        }
    }
    long long total_pair = n - 1;
    long long non_dup_pair = total_pair - dup_pair;
    long long k = 1ll * dup_pair * non_dup_pair;
    k += (1ll * non_dup_pair * (non_dup_pair - 1)) / 2;
    cout << k << endl;
}
int main()
{ // freopen("input.txt", "r", stdin);    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t != 0)
    {
        solve();
        t--;
    }
    return 0;
}