#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string stringHash(string s, int k)
    {
        int n = s.length();
        int t = n / k;
        string ans = "";
        for (int i = 0; i < t; i++)
        {
            long long sum = 0;
            for (int j = 0; j < k; j++)
            {
                sum += (s[i * k + j] - 'a');
            }
            ans += (sum % 26 + 'a');
        }
        return ans;
    }
};

int main()
{
    Solution s;
    // abcd
    cout << s.stringHash("mxz", 3) << endl;
    return 0;
}
