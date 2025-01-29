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
public:
    bool isValid(string s)
    {
        unordered_map<char, char> m = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        stack<char> openBrackets;
        for (auto &b : s)
        {
            if (m.count(b))
            {
                // open bracket
                openBrackets.push(b);
            }
            else
            {
                // close bracket
                if (openBrackets.empty() || m[openBrackets.top()] != b)
                {
                    return false;
                }
                openBrackets.pop();
            }
        }
        return openBrackets.empty();
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    cout << '\n';

    return 0;
}

#endif