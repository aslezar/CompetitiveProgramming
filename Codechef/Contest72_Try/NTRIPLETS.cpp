#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

#define ll long long
#define el << '\n'
#define ws << ' '

const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        ll flag = 0;
        // int a[3] = {0};
        // int l = 0;
        int temp = n;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (temp % i == 0)
            {
                // while (temp % i == 0)
                temp /= i;
                if (temp == i)
                    break;
                cout << 1 ws << i ws << temp el;
                flag = 1;
                break;
                // a[l++] = i;
                // cout << n ws << temp ws << i ws << l el;
                // if (l == 2)
                // {
                //     if (temp != a[0] && temp != a[1])
                //     {
                //         a[l] = temp;
                //     }
                //     else
                //     {
                //         a[l] = temp * 2;
                //     }
                //     if (n / (a[0] * a[1] * a[2]) > 0)
                //         a[2] *= ((n / (a[0] * a[1] * a[2])));
                // }
            }
        }
        if (!flag)
            cout << -1 el;
        //     cout << a[0] ws << a[1] ws << a[2] el;
        // else
        //     // cout<<(()?"YES":"NO") el;
    }
    return 0;
}