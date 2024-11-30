/*
Buy k get 1 free
Input file: standard input
Output file: standard output
Time limit: 1 second
Memory limit: 256 megabytes
You are at a shop with n items numbered 1, 2, . . . n. For each i, the price of the item number i equals Ci
.
There is an offer under which, if you buy any k items, you can get any other item for free, whose price
does not exceed the cheapest of the k items. Please note that, the offer can be used any (including 0)
number of times.
For each m = 1, 2, . . . n, find the minimum amount that you need to pay in order to buy m items.
Input
The first line contains t (1 ≤ t ≤ 105
), the number of test cases. Then, the testcases follow, each consisting
of two lines:
• The first line of each testcase contains two space separated integers, n (2 ≤ n ≤ 2 · 105
) and
k(1 ≤ k ≤ n − 1).
• The next line contains n space separated integers, C1, C2, . . . Cn, where 1 ≤ Ci ≤ 109
for all i.
The sum of n over all testcases doesn’t exceed 2 · 105
.
Output
For each testcase, print a line containing n space separated integers, where the mth of them equals the
minimum amount that you need to pay in order to buy m items.
Example
standard input standard output
2
5 1
4 1 6 10 2
3 2
1 1 1
1 2 5 8 15
1 2 2
Note
In the first testcase, k = 1 and there are 5 items with costs [4, 1, 6, 10, 2]. Consider m = 4. The optimal
solution to buy 4 items is to buy the fifth item(of cost 2) and get the second item(of cost 1 ≤ 2) free with
it, and then buy the third item(of cost 6) and get the first item(of cost 4 ≤ 6) free with it. Hence, the
total amount equals 6 + 2 = 8.
Page 1 of 1
*/
#include <bits/stdc++.h>
using namespace std;

// #define ONLINE_JUDGE
#ifdef LOCAL_RUN
#include "debug.cpp"
#else
#define debug(...) 42
#endif

#define ws << ' '
#define el << '\n'
#define nl cout << '\n';
#define int long long
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define getbit(x, y) (((x) >> (y)) & 1ll)
#define turnonandupdate(x, y) x = ((x) | (1ll << y))
#define turnoffandupdate(x, y) x = (x & ~(1ll << (y)))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define setbits(x) __builtin_popcount(x)
#define sortall(x) sort(all(x))
#define sortallr(x) sort(rall(x))

const bool multipleTest = 1;
const int mod = 1e9 + 7;

void run_case(int currTest)
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sortall(a);
    int sum = 0, free = 0;
    vi sumOfK(n);
    for (int i = 0; i < n; i++)
    {
        sumOfK[i] += a[i];
        if (i - k - 1 >= 0)
            sumOfK[i] += sumOfK[i - k - 1];
    }
    debug(sumOfK);
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (i >= k)
            cout << sum - sumOfK[i - k] ws;
        else
            cout << sum ws;
    }
    nl
}

int32_t main()
{
#ifdef LOCAL_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("log.txt", "w", stderr);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    if (multipleTest)
        cin >> t;
    int T = t;
    while (t--)
    {
        run_case(T - t);
    }
    return 0;
}