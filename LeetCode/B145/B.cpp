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
    int findMinimumTime(const vector<int> &s, int K)
    {
        int ans = INT_MAX;
        vi strength = s;
        int n = (int)strength.size();
        sorta(strength);
        do
        {
            // debug(strength);
            int time = 0;
            int x = 1;
            int energy = 0;
            for (int i = 0; i < n; i++)
            {
                time += max(0, ((strength[i] - energy + x - 1) / x));
                x += K;
                energy = x;
                time++;
            }
            ans = min(ans, time - 1);

        } while (next_permutation(all(strength)));
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    // [], K = 1
    //  [2,5,4], K =2

    cout << s.findMinimumTime({3, 4, 1}, 1) << '\n';
    cout << s.findMinimumTime({2, 5, 4}, 2) << '\n';
    cout << s.findMinimumTime({3}, 8) << '\n';
    cout << s.findMinimumTime({7, 3, 6, 18, 22, 50}, 4) << '\n';

    cout << '\n';

    return 0;
}

#endif