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

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);
}

int32_t main()
{
    freopen("3.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);

    vector<string> v;
    string s;
    while (getline(cin, s))
    {
        v.push_back(s);
    }

    int ans = 0;

    bool enable = true;
    for (auto &str : v)
    {

        auto &s = str;

        for (size_t pos = 0; pos + 4 < str.length(); pos++)
        {

            if (str.substr(pos, 4) == "do()")
            {
                enable = true;
                continue;
            }
            if (str.substr(pos, 7) == "don't()")
            {
                enable = false;
                continue;
            }

            if (str.substr(pos, 4) != "mul(")
                continue;

            pos += 4;

            string a, b;

            for (int i = 0; i < 3; i++)
            {
                if (s[pos] < '0' || s[pos] > '9')
                {
                    break;
                }
                a += s[pos];
                pos++;
            }

            if (s[pos] != ',')
                continue;
            pos++;
            for (int i = 0; i < 3; i++)
            {
                if (s[pos] < '0' || s[pos] > '9')
                {
                    break;
                }
                b += s[pos];
                pos++;
            }
            if (s[pos] != ')')
                continue;
            debug(a, b);

            if (enable)
                ans += (stoi(a) * stoi(b));
            // debug(s[pos+1]);
        }
    }

    // regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    // for (auto &i : v)
    // {
    //     std::regex_iterator<std::string::iterator> it(i.begin(), i.end(), pattern);
    //     std::regex_iterator<std::string::iterator> end;
    //     while (it != end)
    //     {
    //         auto match = *it;
    //         ans += (stoi(match[1]) * stoi(match[2]));
    //         it++;
    //     }
    // }
    cout << ans;
    return 0;
}