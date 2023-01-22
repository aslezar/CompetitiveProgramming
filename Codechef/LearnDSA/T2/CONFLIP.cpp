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
    int t = 0;
    cin >> t;
    while (t--)
    {
        int g = 0, n = 0, i = 0, q = 0;
        cin >> g;
        while (g--)
        {
            cin >> i >> n >> q;
            if (n % 2)
            {
                // odd
                if (i == q)
                {
                    cout << n / 2 el;
                }
                else
                    cout << n / 2 + 1 el;
            }
            else
            {
                // even
                cout << n / 2 el;
            }
        }
    }
    return 0;
}