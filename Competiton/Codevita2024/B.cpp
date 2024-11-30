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

vi count(map<int, vector<vector<int>>> &mp, vector<vector<int>> &m)
{
    vi no;
    for (auto &i : mp)
    {
        auto &v = i.second;
        int bitsDiff = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (v[i][j] != m[i][j])
                {
                    bitsDiff++;
                }
            }
        }
        if (bitsDiff <= 1)
        {
            no.push_back(i.first);
        }
    }
    return no;
}

string add2String(string &a, string &b)
{
    int carr = 0;
    string res;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 && j >= 0)
    {
        int sum = a[i] - '0' + b[j] - '0' + carr;
        res += to_string(sum % 10);
        carr = sum / 10;
        i--, j--;
    }
    while (i >= 0)
    {
        int sum = a[i] - '0' + carr;
        res += to_string(sum % 10);
        carr = sum / 10;
        i--;
    }
    while (j >= 0)
    {
        int sum = b[j] - '0' + carr;
        res += to_string(sum % 10);
        carr = sum / 10;
        j--;
    }
    if (carr)
    {
        res += to_string(carr);
    }
    reverse(all(res));
    return res;
}

void helper(vii &no, int index, string &ans, string curNo)
{
    if (index == (int)no.size())
    {
        ans = add2String(ans, curNo);
        return;
    }
    for (int i = 0; i < (int)(no[index].size()); i++)
    {
        helper(no, index + 1, ans, curNo + (char)(no[index][i] + '0'));
    }
}

void solve([[maybe_unused]] ll &_case_no)
{
    vector<string> v(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
    }
    map<int, vector<vector<int>>> mp;
    for (int no = 0; no <= 9; no++)
    {
        vector<vector<int>> temp(3, vector<int>(3, 0));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp[i][j] = v[i][(no * 3) + j] - '0';
            }
        }
        mp[no] = temp;
    }
    debug(mp);

    vector<string> n(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> n[i];
    }

    vii ans;
    for (int i = 0; i < ((int)n[0].size()) / 3; i++)
    {
        vector<vector<int>> m(3, vector<int>(3, 0));
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                m[j][k] = n[j][(i * 3) + k] - '0';
            }
        }
        ans.push_back(count(mp, m));
        if (ans.back().size() == 0)
        {
            cout << "Invalid";
            return;
        }
    }
    debug(LLONG_MAX);
    debug(ans);
    string res = "";
    helper(ans, 0, res, "");
    cout << res;
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