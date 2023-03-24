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
        ll n = 0;
        cin >> n;
        vector<int> a;
        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            a.push_back(temp);
        }
        temp = 0;
        sort(a.begin(), a.end());
        for (auto &&i : a)
        {
            if(i!=a[0])
                break;
            temp++;
        }
        cout << n - temp el;
    }
    return 0;
}