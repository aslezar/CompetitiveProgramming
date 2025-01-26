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

int NthRoot(int n, int m)
{
    int l = 1, r = INT_MAX;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        double val = pow(mid, n);
        if (val == m)
        {
            // check if val is interger
            if (val - (int)val <= 1e-9)
                return mid;
            return -1;
        }
        else if (val > m)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

#undef int

#ifdef LOCAL_RUN

int main()
{

    cout << '\n';

    return 0;
}

#endif