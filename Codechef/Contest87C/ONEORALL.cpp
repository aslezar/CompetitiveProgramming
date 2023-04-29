#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <climits>
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
        vector<int> a;
        ll sum = 0;
        ll minvalue = INT_MAX;
        for (size_t i = 0; i < n; i++)
        {
            ll temp = 0;
            cin >> temp;
            a.push_back(temp);
            if (temp < minvalue)
                minvalue = temp;
            sum += temp;
        }
        if (n & 1)
        {
            if (sum & 1)
            {
                cout << "CHEF\n";
            }
            else
            {
                cout << "CHEFINA\n";
            }
        }
        else
        {
            if (minvalue & 1 || sum & 1)
                cout << "CHEF\n";
            else
                cout << "CHEFINA\n";
        }
    }
    return 0;
}