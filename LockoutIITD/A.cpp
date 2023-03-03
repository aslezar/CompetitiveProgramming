#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long
#define el << '\n'
#define ws << ' '

const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll n = 0;
    cin >> n;
    if (n < 9)
        cout << -1 el;
    else
    {
        int line = n / 3;
        int torun = line / 3;
        int left = 0;
        if (line % 3 != 0)
        {
            torun--;
            left = 3 + line % 3;
        }
        int a[15];
        for (int i = 0; i < torun; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> a[j];
            }
            cout << a[0] ws << a[4] ws << a[8] ws el;
            cout << a[3] ws << a[7] ws << a[2] ws el;
            cout << a[6] ws << a[1] ws << a[5] ws el;
        }
        if (left == 4)
        {
            for (int i = 0; i < 12; i++)
            {
                cin >> a[i];
            }
            cout << a[0] ws << a[4] ws << a[8] ws el;
            cout << a[3] ws << a[7] ws << a[11] ws el;
            cout << a[6] ws << a[10] ws << a[2] ws el;
            cout << a[9] ws << a[1] ws << a[5] ws el;
        }
        if (left == 5)
        {
            for (int i = 0; i < 15; i++)
            {
                cin >> a[i];
            }
            cout << a[0] ws << a[4] ws << a[8] ws el;
            cout << a[3] ws << a[7] ws << a[11] ws el;
            cout << a[6] ws << a[10] ws << a[14] ws el;
            cout << a[9] ws << a[13] ws << a[2] ws el;
            cout << a[12] ws << a[1] ws << a[5] ws el;
        }
    }
    return 0;
}