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

class Solution
{
    bool helper(string &word1, string &word2, int i, int j, vector<int> &res,
                bool power, set<pair<int, pair<int, bool>>> &dp)
    {
        if (j >= word2.size())
            return true;
        if (i >= word1.size())
            return false;

        if (dp.count({i, {j, power}}))
            return false;

        // if not equal try power
        bool find = false;
        if (word1[i] != word2[j])
        {

            if (power == true)
            {
                find = helper(word1, word2, i + 1, j + 1, res, false, dp);

                if (find == true)
                {
                    res.push_back(i);
                    return true;
                }
            }

            if (find == false)
            {
                while (i < word1.size() && word1[i] != word2[j])
                    i++;
                if (i < word1.size())
                    find = helper(word1, word2, i + 1, j + 1, res, power, dp);
            }
            else
            {
                res.push_back(i);
                return true;
            }
        }
        else
        {

            find = helper(word1, word2, i + 1, j + 1, res, power, dp);
        }

        if (find == true)
        {
            res.push_back(i);
        }
        else
        {
            dp.insert({i, {j, power}});
        }

        return find;
    }

public:
    vector<int> validSequence(string word1, string word2)
    {
        vector<int> res;
        set<pair<int, pair<int, bool>>> dp;

        bool find = helper(word1, word2, 0, 0, res, true, dp);

        reverse(all(res));
        return res;
    }
};