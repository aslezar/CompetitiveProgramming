#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_RUN
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define ws << ' '
#define el << '\n'
#define nl cout << '\n';
#define int long long
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define getbit(x, y) (((x) >> (y)) & 1ll)
#define turnonandupdate(x, y) x = ((x) | (1ll << y))
#define turnoffandupdate(x, y) x = (x & ~(1ll << (y)))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define setbits(x) __builtin_popcount(x)
#define sortall(x) sort(all(x))
#define sortallr(x) sort(rall(x))

const bool multipleTest = 0;
const int mod = 1e9 + 7;

void run_case(int currTest)
{
    vector<string> displays(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> displays[i];
    }
    int ct = 0;
    map<string, int> mp;
    for (int i = 0; i < 30; i += 3)
    {
        string curr = displays[0].substr(i, 3) + displays[1].substr(i, 3) + displays[2].substr(i, 3);
        mp[curr] = ct++;
    }
    debug(mp);
    vector<string> input(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> input[i];
    }
    int m = input[0].size();
    if (m % 3)
    {
        cout << "Invalid\n";
        return;
    }
    vector<set<int>> validDigits;
    for (int i = 0; i < m; i += 3)
    {
        string curr = input[0].substr(i, 3) + input[1].substr(i, 3) + input[2].substr(i, 3);
        validDigits.push_back(set<int>());
        if (mp.find(curr) != mp.end())
        {
            validDigits.back().insert(mp[curr]);
        }
        for (int j = 0; j < curr.size(); j++)
        {
            curr[j] = (curr[j] == '1' ? '0' : '1');
            if (mp.find(curr) != mp.end())
            {
                validDigits.back().insert(mp[curr]);
            }
            curr[j] = (curr[j] == '1' ? '0' : '1');
        }
    }
    if (validDigits.size() > 0 && validDigits[0].count(0))
    {
        validDigits[0].erase(0);
    }
    long double prod = 1;
    for (auto &x : validDigits)
    {
        if (x.empty())
        {
            cout << "Invalid\n";
            return;
        }
        prod *= sz(x);
    }
    debug(prod);
    long double ans = 0;
    long double placeValue = 1;
    for (int i = validDigits.size() - 1; i >= 0; i--)
    {
        int sum = 0;
        for (auto &x : validDigits[i])
        {
            sum += x;
        }
        ans += prod / sz(validDigits[i]) * sum * placeValue;
        placeValue *= 10;
    }
    debug(validDigits);
    cout << ans el;
}

int32_t main()
{
#ifdef LOCAL_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("log.txt", "w", stderr);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    if (multipleTest)
        cin >> t;
    int T = t;
    while (t--)
    {
        run_case(T - t);
    }
    return 0;
}