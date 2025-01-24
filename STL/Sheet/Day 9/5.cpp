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

class Solution12
{
public:
    void partitionHelper(const string &s, int index, int start, vector<string> &p, vector<vector<string>> &ans)
    {
        if (index >= (int)s.length())
        {
            p.push_back(s.substr(start, index - start + 1));
            ans.push_back(p);
            p.pop_back();
            return;
        }

        // push it in curStr
        partitionHelper(s, index + 1, start, p, ans);

        // create new string
        p.push_back(s.substr(start, index - start));
        partitionHelper(s, index + 1, index, p, ans);
        p.pop_back();
    }
    bool isPalindrome(const string &s)
    {
        int l = 0, r = s.length() - 1;
        while (l <= r)
        {
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }
    vector<vector<string>> partition(string s)
    {
        // Solution1
        // {
        //     vector<vector<string>> partitions;
        //     vector<string> p;
        //     partitionHelper(s, 1, 0, p, partitions);

        //     vector<vector<string>> ans;
        //     for (auto &p : partitions)
        //     {
        //         bool ok = true;
        //         for (auto &str : p)
        //         {
        //             if (!isPalindrome(str))
        //             {
        //                 ok = false;
        //                 break;
        //             }
        //         }
        //         if (ok)
        //             ans.push_back(p);
        //     }
        //     return ans;
        // }

        // Solution2
        // {
        //     vector<vector<string>> partitions;
        //     for (int mask = 0; mask < pow(2, s.length() - 1); mask++)
        //     {
        //         bool ok = true;
        //         vector<string> p;
        //         int start = 0;
        //         for (int i = 0; i < s.length() - 1; i++)
        //         {
        //             if (mask & (1 << i))
        //             {
        //                 string sub = s.substr(start, i - start + 1);
        //                 if (!isPalindrome(sub))
        //                 {
        //                     ok = false;
        //                     break;
        //                 }
        //                 p.push_back(sub);
        //                 start = i + 1;
        //             }
        //         }
        //         if (ok)
        //         {
        //             string sub = s.substr(start, s.length() - start + 1);
        //             if (!isPalindrome(sub))
        //             {
        //                 ok = false;
        //                 continue;
        //             }
        //             p.push_back(sub);
        //             partitions.push_back(p);
        //         }
        //     }
        //     debug(partitions);
        //     return partitions;
        // }
    }
};

class Solution
{
public:
    bool isPalindrome(const string &s)
    {
        int l = 0, r = s.length() - 1;
        while (l <= r)
        {
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }
    void helper(const string &s, int index, vector<string> &p, vector<vector<string>> &ans)
    {
        if (index == s.length())
        {
            ans.push_back(p);
            return;
        }
        string curStr;
        for (int i = index; i < s.length(); i++)
        {
            curStr += s[i];
            if (isPalindrome(curStr))
            {
                p.push_back(curStr);
                helper(s, i + 1, p, ans);
                p.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> p;
        helper(s, 0, p, ans);
        debug(ans);
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    s.partition("aab");

    cout << '\n';

    return 0;
}

#endif