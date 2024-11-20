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

bool isValidDivision(vector<int> &arr, int k, int maxDiff)
{
    int subarrays = 1, minElement = INT_MAX, maxElement = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        minElement = min(minElement, arr[i]);
        maxElement = max(maxElement, arr[i]);

        int val = (maxElement - minElement + 1) / 2;

        if (val > maxDiff)
        {
            subarrays++;
            minElement = arr[i];
            maxElement = arr[i];
        }

        if (subarrays > k)
            return false;
    }
    return true;
}

int minimizeMaxDifference(vector<int> &arr, int k)
{
    int l = 0, r = INT_MAX, ans = INT_MAX;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (isValidDivision(arr, k, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    int k = 0;
    cin >> k;

    vi v;
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        cin >> t;
        if (v.empty() || v.back() != t)
        {
            v.push_back(t);
        }
    }
    n = v.size();
    if (n - 1 <= k)
    {
        cout << 0 el;
        return;
    }

    int ans = minimizeMaxDifference(v, k + 1);
    cout << ans el;
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