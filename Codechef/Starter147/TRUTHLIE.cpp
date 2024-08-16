#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> n >> m;
        if (n >= m)
        {
            cout << n + m << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
}
