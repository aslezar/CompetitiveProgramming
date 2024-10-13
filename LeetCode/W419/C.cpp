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
    int win(const char &a, const char &b)
    {
        if (a == b)
            return 0;
        if (a == 'F' && b == 'E' || a == 'W' && b == 'F' ||
            a == 'E' && b == 'W')
            return 1;
        return -1;
    }
    unordered_map<char, int> mp;
    int
    countWinningSequencesHelper(const string &s, int index, int score, const char &C,
                                vector<vector<vector<int>>> &dp)
    {
        int n = s.length();
        if (index >= n)
        {
            return score <= 0 ? 0 : 1;
        }
        if (dp[index][mp[C]][score + n] != -1)
        {
            return dp[index][mp[C]][score + n];
        }
        ll ways = 0;
        if (C != 'F')
            ways += countWinningSequencesHelper(
                s, index + 1, score + win('F', s[index]), 'F', dp);
        if (C != 'W')
            ways += countWinningSequencesHelper(
                s, index + 1, score + win('W', s[index]), 'W', dp);
        if (C != 'E')
            ways += countWinningSequencesHelper(
                s, index + 1, score + win('E', s[index]), 'E', dp);

        ways %= mod;
        dp[index][mp[C]][score + n] = ways;
        return ways;
    }

public:
    int countWinningSequences(const string &s)
    {
        int n = s.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(4, vector<int>(2 * n + 2, -1)));
        mp['A'] = 0;
        mp['E'] = 1;
        mp['F'] = 2;
        mp['W'] = 3;
        int ans = countWinningSequencesHelper(s, 0, 0, 'A', dp);
        return ans;
    }
};
#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    cout << s.countWinningSequences("FFF") << '\n';
    cout << s.countWinningSequences("FWEFW") << '\n';

    return 0;
}

#endif