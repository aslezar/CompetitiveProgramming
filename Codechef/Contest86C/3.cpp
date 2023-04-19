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
        int min_ = INT_MAX;
        vector<int> v;
        for (size_t i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        for (int i = 0; i < n; i++)
        {
            int temp1 = 0, temp2 = 0;

            if (i != 0)
                temp1 = v[i] - v[i - 1];
            if (i != n - 1)
                temp2 = v[i] - v[i + 1];

            if (temp1 < 0)
                temp1 *= -1;
            if (temp2 < 0)
                temp2 *= -1;
            if (max(temp1, temp2) < min_)
                min_ = max(temp1, temp2);
            // cout << 1;
        }
        cout << min_ << '\n';
    }
    return 0;
}