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

double helper(double m, double c, vector<pair<double, double>> &v)
{
    set<double> distance;
    for (int i = 0; i < (int)v.size(); i++)
    {
        double x = v[i].first, y = v[i].second;
        if (abs(m) == numeric_limits<double>::infinity())
        {
            distance.insert(x);
        }
        else
        {
            distance.insert((m * x - y + c) / sqrt(m * m + 1));
        }
    }
    debug(m, c, distance);
    return *distance.rbegin() - *distance.begin();
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vector<pair<double, double>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    int len = 1e4, bre = 1e4;

    // pick any 2 points and calculate the slope
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            double x1 = v[i].first, y1 = v[i].second;
            double x2 = v[j].first, y2 = v[j].second;

            double m = (y2 - y1) / (x2 - x1);
            double c = y1 - m * x1;

            double m2 = -1 / m;
            double c2 = y1 - m2 * x1;

            // disatncce from point i to j
            int curLen = (int)ceil(helper(m, c, v));
            int curBre = (int)ceil(helper(m2, c2, v));

            debug(i, j, curLen, curBre);

            if (len * bre > curLen * curBre)
            {
                len = curLen;
                bre = curBre;
            }
        }
    }
    cout << min(len, bre) << ' ' << max(len, bre);
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}