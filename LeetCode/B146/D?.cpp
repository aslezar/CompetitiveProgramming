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
    int nCr(int n, int r)
    {
        if (r < 0)
            return 0;
        if (n < 0)
            return 0;
        if (r > n)
            return 0;
        if (r == 0)
            return 1;
        if (r > n - r)
            r = n - r;
        int ans = 1;
        for (int i = 1; i <= r; i++)
        {
            ans = ((ans * (n - r + i)) / i) % mod;
        }
        return ans;
    }
    int subsequencesWithMiddleMode(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;

        unordered_map<int, int> fl, fr;
        for (int i = 0; i < n; i++)
        {
            fr[nums[i]]++;
        }
        int unique = fr.size();
        for (int i = 0; i < n; i++)
        {
            int &no = nums[i];
            fr[no]--;
            if (fr[no] == 0)
                fr.erase(no);

            for (int c = 1; c <= 4; c++)
            {
                for (int l = 0; l <= 2; l++)
                {
                    int r = c - l;
                    if (r < 0 || r > 2)
                        continue;
                    if (fl[no] < l or fr[no] < r)
                        continue;

                    int cur = (nCr(fl[no], l) * nCr(fr[no], r)) % mod;

                    if (c == 2)
                    {
                        switch (2 - l)
                        {
                        case 0:
                            break;
                        case 1:
                            cur = (cur * (fl.size() - 1)) % mod;
                            break;
                        case 2:
                            cur = (cur * (unique - 1) * (unique - 2) / 2) % mod;
                            break;

                        default:
                            break;
                        }

                        switch (2 - r)
                        {
                        case 0:
                            break;
                        case 1:
                            cur = (cur * (fr.size() - 1)) % mod;
                            break;
                        case 2:
                            cur = (cur * (fr.size() - 1) * (fr.size() - 2) / 2) % mod;
                            break;

                        default:
                            break;
                        }
                    }
                    else
                    {
                        cur = (cur * nCr(i - fl[no], 2 - l) * nCr(n - i - 1 - fr[no], 2 - r)) % mod;
                    }

                    ans = (ans + cur) % mod;
                    if (fl[no] == 0)
                        fl.erase(no);
                    if (fr[no] == 0)
                        fr.erase(no);
                }
            }

            fl[no]++;
        }
        return ans;
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