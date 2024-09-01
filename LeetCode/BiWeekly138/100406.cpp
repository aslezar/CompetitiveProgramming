#ifdef LOCAL_RUN

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))
#define set_bits __builtin_popcount

#define F first
#define S second
#define PB push_back
#define gcd __gcd
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

constexpr unsigned int mod = 1e9 + 7;
constexpr unsigned int maxn = 1e5 + 4;
constexpr float EPS = numeric_limits<float>::epsilon();
constexpr ll INF = numeric_limits<ll>::max();

class Solution
{
    inline int getFreq(const string &s, int d)
    {
        assert(d >= 0 && d <= 9);
        return s[d] - '0';
    }
    void storeFreqNo(set<string> &s, string &str)
    {

        // debug(str);
        // assert(str[0] != '0');
        // int l = 0, r = str.length() - 1;
        // while (l < r)
        // {
        //     assert(str[l] == str[r]);
        //     l++;
        //     r--;
        // }

        // debug(str);
        string f(10, '0');
        for (auto &i : str)
            f[i - '0']++;
        s.insert(f);
    }
    void helper(set<string> &s, const int n2, int index, string curStr, const int &n, const int &k)
    {
        debug(n2, index, curStr);
        if (index == n2)
        {
            string rev = curStr;
            reverse(all(rev));
            if (n & 1)
            {
                for (char middle = '0'; middle <= '9'; middle++)
                {
                    string str = curStr + middle + rev;
                    ll num = stoll(str);
                    if (num % k == 0)
                        storeFreqNo(s, str);
                }
            }
            else
            {
                string str = curStr + rev;
                ll num = stoll(str);
                if (num % k == 0)
                    storeFreqNo(s, str);
            }
            return;
        }
        for (char c = '0'; c <= '9'; c++)
        {
            if (index == 0 && c == '0')
                continue;
            helper(s, n2, index + 1, curStr + c, n, k);
        }
    }
    void kPalindrome(set<string> &s, const int n, const int &k)
    {
        helper(s, n / 2, 0, "", n, k);
        // debug(s);
    }
    int countNo(const string &s, const int &n, const vi &fact)
    {
        assert(n >= 2 && n <= 10);
        ll cnt = fact[n];

        FOR(c, 0, 9)
        {
            cnt /= fact[getFreq(s, c)];
        }
        // debug(cnt);
        if (getFreq(s, 0) != 0)
        {
            // remove number starting from 0
            ll noStartingFrom0 = fact[n - 1];
            noStartingFrom0 /= (fact[getFreq(s, 0) - 1]);
            FOR(i, 1, 9)
            {
                noStartingFrom0 /= (fact[getFreq(s, i)]);
            }
            // debug(s, noStartingFrom0);
            cnt = cnt - noStartingFrom0;
        }

        return cnt;
    }

public:
    long long countGoodIntegers(int n, int k)
    {
        long long ans = 0;
        if (n == 1)
        {
            FOR(i, 1, 9)
            if (i % k == 0)
                ans++;
            return ans;
        }

        vi fact;
        fact.PB(1);
        FOR(i, 1, 10)
        fact.PB(fact.back() * i);
        // debug(fact);

        set<string> s;
        kPalindrome(s, n, k);

        debug(s.size());

        for (auto &str : s)
            ans += countNo(str, n, fact);

        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    // cout << s.countGoodIntegers(3, 5);
    cout << endl;
    cout << s.countGoodIntegers(5, 6);
    cout << endl;

    return 0;
}

#endif

// find all palindromes of length n and div by k
// set of all freq of these