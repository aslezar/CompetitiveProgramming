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
#define ws << " "

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
constexpr unsigned int mod = 1e9 + 7;

bool isInt(double value)
{
    return std::floor(value) == value;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll k = 0;
    cin >> k;

    map<int, int> m;
    int t = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> t;
        m[t]++;
    }

    for (auto &i : m)
    {
        double no = (k - 2.0) / (i.first * 1.0);
        debug(no);
        debug(no);
        if (isInt(no))
        {
            int ino = no;
            if (ino == i.first && i.second >= 2)
            {
                cout << i.first ws << i.first el;
                return;
            }
            else if (ino != i.first && m[ino] > 0)
            {
                cout << i.first ws << ino el;
                return;
            }
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