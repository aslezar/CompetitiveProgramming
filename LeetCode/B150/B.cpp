#ifdef LOCAL_RUN
#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

// #define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        double l = 0, r = INT_MAX;
        double ans = INT_MAX;

        constexpr double EPS = numeric_limits<double>::epsilon();

        while (r - l > 0.00001)
        {
            double mid = l + (r - l) / 2;

            double tArea = 0, bArea = 0;
            for (auto &sq : squares)
            {
                double x = sq[0];
                double y = sq[1];
                double len = sq[2];
                double w = len;
                double hb = min(len, max(0.0, mid - y));
                double ht = min(len, max(0.0, y + len - mid));
                tArea += (w * ht);
                bArea += (w * hb);
            }

            debug(mid, bArea, tArea);

            if (bArea >= tArea)
            {
                ans = min(ans, mid);
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return ans;
    }
};
#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    // [[0,0,2],[1,1,1]]©leetcod
    vii v = {{0, 0, 2}, {1, 1, 1}};
    double ans = s.separateSquares(v);
    debug(ans);
    cout << '\n';

    return 0;
}

#endif