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

void testcase()
{
    ll n = 0;
    cin >> n;
    assert(n >= 1 && n <= 1e9);

    string a, b, c(n, '0');
    cin >> a;
    reverse(a.begin(), a.end());
    b = a;
    // cout << a << ' ' << b << ' ' << c << '\n';

    for (int i = 0; i < n; i++)
    {
        if (b[i] == '0')
            continue;
        int j = i;
        while (j < n && b[j] == '1')
            j++;
        if (j - i == 1)
            continue;
        if (j == n)
            break;
        c[i] = '1';
        while (i < j)
            b[i++] = '0';
        b[j] = '1';
        --i;
    }
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    cout << b << '\n'
         << c << '\n';
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