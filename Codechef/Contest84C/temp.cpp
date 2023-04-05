#include <iostream>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    long long ans = 1; // start with 1 to avoid multiplying by 0 later

    for (int i = 1; i <= n - 3; i++)
    {
        ans = (ans * i) % MOD; // compute (n-3)!
    }

    ans = (ans * (pow(2, n) - 2)) % MOD; // multiply by (2^n - 2)

    cout << ans << endl;
    return 0;
}
