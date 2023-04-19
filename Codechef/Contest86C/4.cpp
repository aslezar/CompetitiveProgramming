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
    ll t = 0;
    cin >> t;
    while (t--)
    {
        cout << t << '\n';
        ll n = 0;
        cin >> n;
        string s;
        cin >> s;
        if (n == 1)
        {
            cout << "Ramos" << '\n';
            continue;
        }
        // int c = 0;
        // for (int i = 0; i < s.length() - 1; i++)
        // {
        //     if (s[i] != s[i + 1])
        //     {
        //         s.erase(i, 2);
        //         c++;
        //         i = max(i - 2, -1);
        //     }
        // }
        // // cout << c;
        // if (c % 2 == 0)
        // {
        //     cout << "Ramos\n";
        // }
        // else
        // {
        //     cout << "Zlatan\n";
        // }
    }
    return 0;
}