#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int sumOfNSquareNo(int n)
{
    long long n1 = n;
    long long n2 = n + 1;
    long long n3 = 2 * n + 1;

    if (n1 % 2 == 0)
        n1 /= 2;
    else
        n2 /= 2;

    if (n1 % 3 == 0)
        n1 /= 3;
    else if (n2 % 3 == 0)
        n2 /= 3;
    else
        n3 /= 3;

    long long result = n1 % MOD;
    result = (result * (n2 % MOD)) % MOD;
    result = (result * (n3 % MOD)) % MOD;
    return static_cast<int>(result);
}

int solve(int n)
{
    int ans = 0;
    for (int a = 1; a <= n - 1; a++)
    {
        long long term = (static_cast<int>(pow(2, n - a)) % MOD) * sumOfNSquareNo(a) % MOD;
        cout << term << " ";
        ans = (ans + term) % MOD;
    }
    cout << endl;
    return ans;
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
