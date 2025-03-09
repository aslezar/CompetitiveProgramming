#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_RUN
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))
#define input(vec, n)           \
    for (int i = 0; i < n; i++) \
        std::cin >> vec[i];

#define el << endl;
#define ws << " ";

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
constexpr unsigned int mod = 1e9 + 7;

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    int b = 0;
    cin >> b;

    if (n == 1)
    {
        if (b == 3)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
            cout << "1\n";
            cout << "1 3 1" << '\n';
        }
        return;
    }

    if (b == 4)
    {
        cout << "Yes\n";
        switch (n % 4)
        {
        case 0:
            cout << n / 4 << '\n';
            for (int i = 1; i <= n; i += 4)
            {
                cout << "4 2 " << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << '\n';
            }
            break;
        case 1:
            cout << n / 4 + 1 << '\n';
            cout << "1 3 1" << '\n';
            for (int i = 2; i <= n; i += 4)
            {
                cout << "4 2 " << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << '\n';
            }
            break;
        case 2:
            cout << n / 4 + 2 << '\n';
            cout << "1 3 1" << '\n';
            cout << "1 1 2" << '\n';
            for (int i = 3; i <= n; i += 4)
            {
                if (i == 3)
                {
                    cout << "4 6 " << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << '\n';
                }
                cout << "4 2 " << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << '\n';
            }
            break;
        case 3:
            cout << n / 4 + 2 << '\n';
            cout << "2 5 1 3" << '\n';
            cout << "1 1 2" << '\n';
            for (int i = 4; i <= n; i += 4)
            {
                cout << "4 2 " << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << '\n';
            }
            break;
        }
        return;
    }

    cout << "Yes\n";
    if (n & 1)
    {
        cout << n / 2 << '\n';
        cout << "3 4 1 2 3" << '\n';
        for (int i = 4; i <= n; i += 2)
        {
            cout << "2 4 " << i << " " << i + 1 << '\n';
        }
    }
    else
    {
        cout << n / 2 << '\n';
        for (int i = 1; i <= n; i += 2)
        {
            cout << "2 4 " << i << " " << i + 1 << '\n';
        }
    }
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}