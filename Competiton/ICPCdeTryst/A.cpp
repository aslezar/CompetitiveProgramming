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

int modpow(int base, int exp, int modulus)
{
    base %= modulus;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0, p = 0;
        vector<int> no;
        cin >> n >> p;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            cin >> temp;
            no.push_back(temp);
        }
        ll final = 0;
        if (n == 1)
        {
            cout << 0 el;
            continue;
        }
        bool flag = 0;
        for (int i = 1; i < n; i++)
        {
            if (no[i] < no[i - 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << 0 el;
            continue;
        }
        int firstno = no[0];
        if (no[0] < no[1])
        {
            firstno++;
        }
        vector<int> ans;
        int carry = 0;
        for (int i = n - 1; i > 0; i--)
        {
            int temp = firstno - no[i] - carry;
            if (temp < 0)
            {
                temp += p;
                carry = 1;
            }
            ans.push_back(temp);
        }
        for (int i = 0; i < ans.size(); i++)
        {
            final = final + ((ans[i] * (modpow(p, i, mod))) % mod);
        }
        cout << final el;
    }
    return 0;
}