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
        ll length = 0;
        string given_str;
        cin >> length >> given_str;
        for (int i = 0; i < length;)
        {
            int cnt = 0;
            for (int j = i; j < length; j++)
            {
                if (given_str[i] != given_str[j])
                    break;
                cnt++;
            }
            cout << given_str[i];
            if (cnt % 2 == 0)
                cout << given_str[i];
            i += cnt;
        }
        cout << '\n';
    }
    return 0;
}