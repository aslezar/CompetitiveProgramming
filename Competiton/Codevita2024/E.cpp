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

int orientation(pair<double, double> p, pair<double, double> q, pair<double, double> r)
{
    double val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
    if (abs(val) < 1e-9)
        return 0;
    return (val > 0) ? 1 : 2;
}

bool compare(pair<double, double> p1, pair<double, double> p2, pair<double, double> ref)
{
    int o = orientation(ref, p1, p2);
    if (o == 0)
        return hypot(p1.first - ref.first, p1.second - ref.second) <
               hypot(p2.first - ref.first, p2.second - ref.second);
    return o == 2;
}

vector<pair<double, double>> convexHull(vector<pair<double, double>> &points)
{
    int n = points.size();

    int minY = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].second < points[minY].second ||
            (points[i].second == points[minY].second && points[i].first < points[minY].first))
        {
            minY = i;
        }
    }
    swap(points[0], points[minY]);

    pair<double, double> ref = points[0];
    sort(points.begin() + 1, points.end(), [&](pair<double, double> p1, pair<double, double> p2)
         { return compare(p1, p2, ref); });

    vector<pair<double, double>> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for (int i = 2; i < n; i++)
    {
        while (hull.size() > 1 && orientation(hull[hull.size() - 2], hull.back(), points[i]) != 2)
        {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}

double polygonArea(const vector<pair<double, double>> &points)
{
    int n = points.size();

    double area = 0.0;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        area += points[i].first * points[j].second - points[j].first * points[i].second;
    }
    return abs(area) / 2.0;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vector<vector<double>> v(n, vector<double>(4));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> v[i][j];
        }
    }

    set<pair<double, double>> intersection;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            double x1 = v[i][0], y1 = v[i][1], x2 = v[i][2], y2 = v[i][3];

            double a1 = y2 - y1;
            double b1 = x1 - x2;
            double c1 = a1 * x1 + b1 * y1;

            double x3 = v[j][0], y3 = v[j][1], x4 = v[j][2], y4 = v[j][3];

            double a2 = y4 - y3;
            double b2 = x3 - x4;
            double c2 = a2 * x3 + b2 * y3;

            double intersection_x = (b2 * c1 - b1 * c2) / (a1 * b2 - a2 * b1);
            double intersection_y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);

            if (intersection_x >= min(x1, x2) && intersection_x <= max(x1, x2) && intersection_x >= min(x3, x4) && intersection_x <= max(x3, x4) && intersection_y >= min(y1, y2) && intersection_y <= max(y1, y2) && intersection_y >= min(y3, y4) && intersection_y <= max(y3, y4))
            {
                intersection.insert({intersection_x, intersection_y});
            }
        }
    }
    vector<pair<double, double>> v2(intersection.begin(), intersection.end());
    auto hull = convexHull(v2);

    cout << polygonArea(hull) << endl;
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