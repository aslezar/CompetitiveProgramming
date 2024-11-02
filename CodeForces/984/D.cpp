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

bool isExist(int i, vi &l)
{
    int n = l.size();
    if (n < 4)
        return false;
    if (l[(i % n)] == 1 && l[(i + 1) % n] == 5 && l[(i + 2) % n] == 4 && l[(i + 3) % n] == 3)
    {
        return true;
    }
    return false;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    ll m = 0;
    cin >> m;

    vector<string> a(n);
    input(a, n);

    vii matrix(n, vi(m));

    // debug(a);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = a[i][j] - '0';
        }
    }
    debug(matrix);

    int ans = 0;

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;

    while (top <= bottom && left <= right)
    {
        vi layer;
        // top row
        for (int s = left; s <= right; s++)
            layer.push_back(matrix[top][s]);

        // right col
        for (int s = top + 1; s <= bottom; s++)
            layer.push_back(matrix[s][right]);

        // bottom row
        if (bottom != top)
            for (int s = right - 1; s >= left; s--)
                layer.push_back(matrix[bottom][s]);

        // left col
        if (left != right)
            for (int s = bottom - 1; s >= top + 1; s--)
                layer.push_back(matrix[s][left]);

        top++;
        bottom--;
        left++;
        right--;

        for (size_t i = 0; i < layer.size(); i++)
        {
            if (isExist(i, layer))
            {
                ans++;
            }
        }
    }

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