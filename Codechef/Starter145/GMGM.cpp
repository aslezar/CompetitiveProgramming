#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t > 0)
    {
        int d, n;
        cin >> n >> d;
        int ans = 0;
        bool isShortRange = true;
        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp <= d)
            {
                if (!isShortRange)
                {
                    isShortRange = true;
                    ans++;
                }
            }
            else
            {
                if (isShortRange)
                {
                    isShortRange = false;
                    ans++;
                }
            }
        }
        cout << ans << endl;
        t--;
    }
    return 0;
}
