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
int32_t main()
{
    freopen("5.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);

    map<int, vi> m;
    string s;
    while (cin >> s)
    {
        if (s.find('|') == string::npos)
            break;
        // split s by '|'
        vector<string> v;
        string temp = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '|')
            {
                v.push_back(temp);
                temp = "";
            }
            else
            {
                temp += s[i];
            }
        }
        v.push_back(temp);
        assert(v.size() == 2);
        m[stoi(v[0])].push_back(stoi(v[1]));
    }
    int ans = 0;
    do
    {
        // split by ,
        vector<int> v;
        string temp = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ',')
            {
                v.push_back(stoi(temp));
                temp = "";
            }
            else
            {
                temp += s[i];
            }
        }
        v.push_back(stoi(temp));
        debug(v);
        bool correct = true;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                for (auto &x : m[v[i]])
                {
                    if (x == v[j])
                    {
                        correct = false;
                        swap(v[i], v[j]);
                    }
                }
            }
        }
        if (!correct)
        {
            ans += v[v.size() / 2];
        }

    } while (cin >> s);

    cout << ans el;

    return 0;
}