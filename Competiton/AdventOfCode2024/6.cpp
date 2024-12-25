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

bool inLimit(pii pos, const vector<string> &v)
{
    int i = pos.first, j = pos.second;
    return i >= 0 && i < (int)v.size() && j >= 0 && j < (int)v[i].size();
}

int32_t main()
{
    freopen("6.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);

    vector<string> vv;
    string s;
    while (getline(cin, s))
    {
        vv.push_back(s);
    }
    pair<int, int> position = {-1, -1};
    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[i].length(); j++)
        {
            if (vv[i][j] == '^')
            {
                position = {i, j};
                break;
            }
        }
    }

    vector<pii> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int curDir = 0;

    int cnt = 0;

    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
        {
            if (vv[i][j] != '.')
                continue;
            auto v = vv;
            auto pos = position;

            v[i][j] = '#';
            set<pair<pii, int>> visited;
            visited.insert({pos, curDir});
            while (inLimit(pos, v))
            {
                v[pos.first][pos.second] = 'X';
                pii &dir = dirs[curDir];
                pii next = {pos.first + dir.first, pos.second + dir.second};
                if (inLimit(next, v) && v[next.first][next.second] == '#')
                {
                    curDir = (curDir + 1) % 4;
                }
                else
                {
                    pos = next;
                    if (visited.count({pos, curDir}))
                    {
                        cnt++;
                        break;
                    }
                    visited.insert({pos, curDir});
                }
            }
        }
    }

    cout << cnt;
    return 0;
}