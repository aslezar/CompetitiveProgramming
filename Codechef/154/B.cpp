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
constexpr unsigned int mod = 1e9 + 7;

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    ll k = 0;
    cin >> k;

    vi arr(n);
    input(arr, n);

    bool areAllEqual = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != k)
        {
            areAllEqual = false;
            break;
        }
    }
    if (areAllEqual)
    {
        cout << "0\n";
        return;
    }
    bool isMul = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % k != 0)
        {
            isMul = false;
            break;
        }
    }
    if (isMul)
    {
        cout << "1\n";
        return;
    }
    int firstUnEqual = -1;
    int lastUnEqual = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != k)
        {
            firstUnEqual = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != k)
        {
            lastUnEqual = i;
            break;
        }
    }

    bool areAllUnEqualAreEqual = true;
    for (int i = firstUnEqual; i <= lastUnEqual; i++)
    {
        if (arr[i] != arr[firstUnEqual])
        {
            areAllUnEqualAreEqual = false;
            break;
        }
    }
    if (areAllUnEqualAreEqual)
    {
        cout << "1\n";
        return;
    }
    cout << "2\n";
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