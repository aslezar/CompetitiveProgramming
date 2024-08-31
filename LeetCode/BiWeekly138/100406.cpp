#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    long long countGoodIntegers(int n, int k)
    {
        // smallest number having n digits
        long long small = 1;
        for (int i = 1; i < n; i++)
            small = small * 10;
        long long large = small * 10 - 1;

        long long start = small;
        while (start % k != 0)
            start++;

        long long ans = 0;
        set<string> vis;

        for (long long i = start; i <= large; i += k)
        {
            string digits = to_string(i);
            if (vis.find(digits) != vis.end())
                continue;

            bool isPal = isPalindrome(digits);
            if (isPal == false)
                continue;

            sort(digits.begin(), digits.end());

            do
            {
                long long num = stoll(digits);
                if (vis.find(digits) == vis.end() && num >= small && num <= large)
                {
                    vis.insert(digits);
                    ans++;
                }
            } while (next_permutation(digits.begin(), digits.end()));
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.countGoodIntegers(5, 6) << endl;
    return 0;
}
