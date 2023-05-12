#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <assert.h>
using namespace std;

#define el << '\n'
#define ws << ' '

typedef long long ll;
typedef long double ld;
const int N = 1e5 + 5, M = 1e9 + 7;

class Fun
{
public:
    // For Mod Mul
    static inline int mul(int a, int b)
    {
        return 1LL * a * b % M;
    }
    // For Mod Power
    static int power(int b, int p)
    {
        if (p == 0)
            return 1;
        int x = power(b, p / 2);
        return p % 2 == 0 ? mul(x, x) : mul(b, mul(x, x));
    }
    // For Inverse Mod
    static int modInvFer(int n)
    {
        return power(n, M - 2);
    }
} fun;
bool valid(int d, int m, int y)
{
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        if (d < 32)
            return true;
        else
            return false;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        if (d < 31)
            return true;
        else
            return false;
    }
    if (m == 2)
    {
        if (d < 29)
            return true;
        else if (d == 29 && y % 4 == 0)
            return true;
        else
            return false;
    }
    return false;
}

void testcase()
{
    string s;
    cin >> s;
    int d = 0, m = 0, y = 0;
    d = (s[0] - '0') * 10 + (s[1] - '0');
    m = (s[3] - '0') * 10 + (s[4] - '0');
    y = ((s[6] - '0') * 1000) + ((s[7] - '0') * 100) + ((s[8] - '0') * 10) + (s[9] - '0');
    int a = valid(d, m, y);
    int b = valid(m, d, y);
    if (a && b)
        cout << "BOTH\n";
    else if (a)
    {
        cout << "DD/MM/YYYY\n";
    }
    else if (b)
    {
        cout << "MM/DD/YYYY\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        testcase();
    return 0;
}