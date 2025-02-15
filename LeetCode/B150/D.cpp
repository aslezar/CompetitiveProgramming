#ifdef LOCAL_RUN
#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

// #define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

vector<int> kmp(string &String, string &pattern)
{
    int i = 0, j = 0, m = pattern.length(), n = String.length();
    pattern = ' ' + pattern; // just shifting the pattern indices by 1
    vector<int> piTable(m + 1, 0);
    for (int i = 2; i <= m; i++)
    {
        while (j <= m && pattern[j + 1] == pattern[i])
            piTable[i++] = ++j;
        j = 0;
    }
    j = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (pattern[j + 1] != String[i])
        {
            while (j != 0 && pattern[j + 1] != String[i])
                j = piTable[j];
        }
        j++;
        if (j == m)
        {
            ans.push_back(i - m + 1);
            // return i - m + 1;
        }
    }
    return ans;
}

class Solution
{
public:
    int shortestMatchingSubstring(string s, string p)
    {
        vector<vi> pp;
        for (int i = 0; i < p.length(); i++)
        {
            string ss;
            while (i < p.length())
            {
                if (p[i] == '*')
                    break;
                ss += p[i];
                i++;
            }
            if (ss.length() == 0)
            {
                continue;
            }
            pp.push_back(kmp(s, ss));
        }
        debug(pp);
        return 0;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    string str = "abaacbaecebce", p = "ba*c*ce";
    cout << s.shortestMatchingSubstring(str, p);
    cout << '\n';

    return 0;
}

#endif