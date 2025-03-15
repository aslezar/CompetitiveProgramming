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
    vector<int> search(const string &pat, const string &txt)
    {
        int n = txt.length();
        int m = pat.length();
        vector<int> pi(m, 0);
        for (int i = 1; i < m; i++)
        {
            int j = 0;
            while (i < m && pat[i] == pat[j])
            {
                pi[i] = j + 1;
                i++;
                j++;
            }
        }
        debug(pi);

        vector<int> ans;

        int j = -1;
        for (int i = 0; i < n; i++)
        {
            if (j + 1 < m && txt[i] == pat[j + 1])
            {
                j++;
                if (j + 1 == m)
                {
                    debug(i, j);
                    ans.push_back(i - m + 1);
                    j = pi[j] - 1;
                }
            }
            else if (j != -1)
            {
                j = pi[j + 1] - 1;
                i--;
            }
            debug(i, j);
        }

        debug(ans);
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    string txt, pat;
    cin >> txt >> pat;

    debug(txt.length());

    auto start = chrono::high_resolution_clock::now();

    s.search(pat, txt);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << (duration);

    cout << '\n';

    return 0;
}

#endif