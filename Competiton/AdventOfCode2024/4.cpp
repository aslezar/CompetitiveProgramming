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

const string word = "XMAS";

int rev(string s)
{
    int cnt = 0;
    if (s == word)
    {
        cnt++;
    }
    reverse(all(s));
    if (s == word)
    {
        cnt++;
    }
    return cnt;
}

bool inLimit(int i, int j, const vector<string> &v)
{
    return i >= 0 && i < (int)v.size() && j >= 0 && j < (int)v[i].size();
}

int count(int i, int j, const vector<string> &v)
{
    int cnt = 0;
    // left
    if (j + 4 <= (int)v[i].length())
    {
        string left = v[i].substr(j, 4);
        cnt += rev(left);
    }

    // right
    if (j - 3 >= 0)
    {
        string right = v[i].substr(j - 3, 4);
        cnt += rev(right);
    }

    if (i - 3 >= 0)
    {
        string up;
        for (int k = i - 3; k <= i; k++)
        {
            up.push_back(v[k][j]);
        }
        cnt += rev(up);
    }

    if (i + 4 <= (int)v.size())
    {
        string down;
        for (int k = i; k < i + 4; k++)
        {
            down.push_back(v[k][j]);
        }
        cnt += rev(down);
    }

    vector<string> str(4);

    for (int m = 0; m < 4; m++)
    {
        if (inLimit(i + m, j + m, v))
            str[0].push_back(v[i + m][j + m]);
        if (inLimit(i + m, j - m, v))
            str[1].push_back(v[i + m][j - m]);
        if (inLimit(i - m, j - m, v))
            str[2].push_back(v[i - m][j - m]);
        if (inLimit(i - m, j + m, v))
            str[3].push_back(v[i - m][j + m]);
    }
    debug(str);
    for (int t = 0; t < 4; t++)
    {
        if ((int)str[t].length() == 4 && str[t] == word)
            cnt++;
    }
    return cnt;
}

void solve()
{
    vector<string> v;
    string s;
    while (getline(cin, s))
    {
        v.push_back(s);
    }

    int ans = 0;
    for (int i = 0; i < (int)v.size(); i++)
    {
        for (int j = 0; j < (int)v[i].length(); j++)
        {
            if (v[i][j] == 'X')
            {

                ans += count(i, j, v);
            }
        }
    }
    cout << ans << '\n';

    int ans2 = 0;
    for (int i = 0; i < (int)v.size(); i++)
    {
        for (int j = 0; j < (int)v[i].length(); j++)
        {
            if (v[i][j] == 'A')
            {
                int cnt = 0;
                if (inLimit(i + 1, j + 1, v) && inLimit(i - 1, j - 1, v) && inLimit(i - 1, j + 1, v) && inLimit(i + 1, j - 1, v))
                {

                    if (v[i + 1][j + 1] == 'M' && v[i - 1][j - 1] == 'S')
                    {
                        cnt++;
                    }
                    if (v[i + 1][j + 1] == 'S' && v[i - 1][j - 1] == 'M')
                    {
                        cnt++;
                    }
                    if (v[i - 1][j + 1] == 'M' && v[i + 1][j - 1] == 'S')
                    {
                        cnt++;
                    }
                    if (v[i - 1][j + 1] == 'S' && v[i + 1][j - 1] == 'M')
                    {
                        cnt++;
                    }
                }
                if (cnt == 2)
                    ans2++;
            }
        }
    }
    cout << ans2;
}

int32_t main()
{
    freopen("4.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    solve();
    return 0;
}