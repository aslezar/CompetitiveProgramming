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

typedef vector<string> vs;
typedef vector<vector<string>> vss;

void wordBreakHelper(int index, vs &p, vs &ans, string &s, set<string> &dictionary)
{
    if (index >= s.length())
    {
        string str;
        for (auto &ss : p)
            str += (ss + ' ');
        str.pop_back();
        ans.push_back(str);
        return;
    }

    string cur;
    for (int i = index; i < s.length(); i++)
    {
        cur += s[i];
        if (dictionary.count(cur))
        {
            p.push_back(cur);
            wordBreakHelper(i + 1, p, ans, s, dictionary);
            p.pop_back();
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vs ans;
    vs p;

    set<string> dict;
    for (auto &i : dictionary)
        dict.insert(i);

    wordBreakHelper(0, p, ans, s, dict);
    return ans;
}

#undef int

#ifdef LOCAL_RUN

int main()
{
    cout << '\n';

    return 0;
}

#endif