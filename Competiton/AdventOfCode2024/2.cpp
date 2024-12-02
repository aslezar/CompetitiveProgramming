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

bool isSafe(vi &lvl)
{
    if (!(is_sorted(all(lvl)) || is_sorted(rall(lvl))))
        return false;

    bool ok = true;
    for (int i = 1; i < (int)lvl.size(); i++)
    {
        int diff = abs(lvl[i] - lvl[i - 1]);
        if (diff < 1 || diff > 3)
        {
            ok = false;
            break;
        }
    }
    return ok;
}

void solve(vii &v)
{
    int safe = 0;
    for (auto &lvl : v)
    {
        if (isSafe(lvl))
        {
            safe++;
            continue;
        }
        for (int i = 0; i < lvl.size(); i++)
        {
            vi newLvl;
            for (int j = 0; j < lvl.size(); j++)
            {
                if (i != j)
                    newLvl.push_back(lvl[j]);
            }
            if (isSafe(newLvl))
            {
                safe++;
                break;
            }
        }
    }
    cout << safe;
}

int32_t main()
{
    freopen("2.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);

    vii v;
    string line;

    while (getline(cin, line))
    {
        istringstream iss(line);
        int num = 0;
        v.push_back({});
        while (iss >> num)
        {
            v.back().push_back(num);
        }
    }
    solve(v);
    return 0;
}