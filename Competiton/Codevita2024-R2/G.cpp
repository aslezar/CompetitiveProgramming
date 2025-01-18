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

void sortAndMerge(map<int, vector<pii>> &m)
{
    for (auto &i : m)
    {
        sorta(i.second);
        // merge
        for (int j = 0; j < (int)i.second.size(); j++)
        {
            if (j + 1 < (int)i.second.size() && i.second[j].second >= i.second[j + 1].first)
            {
                i.second[j].second = max(i.second[j].second, i.second[j + 1].second);
                i.second.erase(i.second.begin() + j + 1);
                j--;
            }
        }
    }
}

pii intersectionPoint(vi &a, vi &b)
{
    double x1 = a[0], y1 = a[1], x2 = a[2], y2 = a[3];
    double x3 = b[0], y3 = b[1], x4 = b[2], y4 = b[3];

    if (x1 == x2 && x3 == x4)
    {
        return {-1, -1};
    }
    if (y1 == y2 && y3 == y4)
    {
        return {-1, -1};
    }

    double denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (std::abs(denom) < 1e-9)
        return {-1, -1};

    double px = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / denom;
    double py = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / denom;

    if (px < std::min(x1, x2) || px > std::max(x1, x2) || px < std::min(x3, x4) || px > std::max(x3, x4) ||
        py < std::min(y1, y2) || py > std::max(y1, y2) || py < std::min(y3, y4) || py > std::max(y3, y4))
    {
        return {-1, -1};
    }

    if (px == 0 && py == 1)
    {
        debug(a, b);
    }

    return {px, py};
}

double diagnoalLength(int x1, int y1, int x2, int y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

struct Point
{
    int x;
    int y;
};

void solve([[maybe_unused]] ll &_case_no)
{
    int c, r;
    cin >> c >> r;
    int s, n;
    cin >> s >> n;

    debug(c, r, s, n);

    map<int, vector<pii>> v, h;

    for (int i = 0; i < n; i++)
    {
        vector<Point> a(2);
        for (int j = 0; j < 2; j++)
        {
            cin >> a[j].x >> a[j].y;
        }
        if (a[0].x == a[1].x)
        {
            v[a[0].x].push_back({min(a[0].y, a[1].y), max(a[0].y, a[1].y)});
        }
        else
        {
            h[a[0].y].push_back({min(a[0].x, a[1].x), max(a[0].x, a[1].x)});
        }
    }

    v[0].push_back({0, r});
    v[c].push_back({0, r});

    h[0].push_back({0, c});
    h[r].push_back({0, c});

    sortAndMerge(v);
    sortAndMerge(h);

    debug(v);
    debug(h);

    for(auto &hh:h){
        int no=1;
        for(auto &vv:v){
            
        }
    }

    // vector<vector<int>> v(n, vector<int>(4));

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cin >> v[i][j];
    //     }
    // }
    // v.push_back({0, 0, 0, r});
    // v.push_back({0, 0, c, 0});
    // v.push_back({0, r, c, r});
    // v.push_back({c, 0, c, r});

    // // vii grid(c, vi(n, 0));

    // vector<pii> p;
    // for (int i = 0; i < (int)v.size(); i++)
    // {
    //     for (int j = i + 1; j < (int)v.size(); j++)
    //     {
    //         auto point = intersectionPoint(v[i], v[j]);
    //         if (point.first != -1 && point.second != -1)
    //         {
    //             p.push_back(point);
    //         }
    //     }
    // }
    // sorta(p);
    // debug(p);

    // set<pii> e;
    // for (auto &p : p)
    // {
    //     e.insert(p);
    // }

    // int area = 0;
    // int cnt = 0;

    // for (int i = 0; i < (int)p.size(); i++)
    // {
    //     int findx = 1000, findy = 1000;
    //     for (int j = 0; j < (int)p.size(); j++)
    //     {
    //         if (i == j)
    //             continue;
    //         auto &p1 = p[i];
    //         auto &p2 = p[j];
    //         if (p2.first > p1.first && p2.second > p1.second)
    //         {
    //             if (e.count({p2.first, p1.second}) && e.count({p1.first, p2.second}))
    //             {
    //                 int w = p2.first - p1.first;
    //                 int h = p2.second - p1.second;
    //                 if (w * h < (findx - p1.first) * (findy - p1.second))
    //                 {
    //                     findx = p2.first;
    //                     findy = p2.second;
    //                 }
    //             }
    //         }
    //     }
    //     if (findx == 1000 || findy == 1000)
    //     {
    //         continue;
    //     }
    //     int w = findx - p[i].first;
    //     int h = findy - p[i].second;
    //     debug(p[i], findx, findy, w, h);
    //     if (w <= s && h <= s)
    //     {
    //         area += (w * h);
    //         cnt++;
    //     }
    // }
    // debug(cnt);
    // cout << area << '\n';
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