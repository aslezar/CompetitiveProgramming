#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define el << '\n'
#define ws << ' '

bool samefreq(map<int, int> a, map<int, int> b)
{
    for (int i = 0; i < 26; i++)
    {
        if (a['a' + i] != b['a' + i])
            return 0;
    }
    return 1;
}

vector<int> findAnagrams(string s, string p)
{
    if (s.length() < p.length())
        return {};
    map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < p.size(); i++)
    {
        m[p[i]]++;
    }
    map<int, int> f;
    int start = 0;
    int end = p.size();
    for (int i = 0; i < end; i++)
    {
        f[s[i]]++;
    }
    if (samefreq(m, f))
        ans.push_back(start);
    for (int i = 0; i < s.size() - p.size(); i++)
    {
        f[s[start]]--;
        start++;
        f[s[end]]++;
        end++;
        if (samefreq(m, f))
            ans.push_back(start);
    }
    return ans;
}

int main()
{
    string s = "cbaebabacd", p = "abc";
    vector<int> a(findAnagrams(s, p));
    for (auto &&i : a)
    {
        cout << i ws;
    }
    return 0;
}