#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int generateKey(int num1, int num2, int num3)
    {
        string a = to_string(num1);
        string b = to_string(num2);
        string c = to_string(num3);

        if (a.length() < 4)
            a = string(4 - a.length(), '0') + a;
        if (b.length() < 4)
            b = string(4 - b.length(), '0') + b;
        if (c.length() < 4)
            c = string(4 - c.length(), '0') + c;

        // cout << a << " " << b << " " << c << endl;

        string ans = "    ";
        for (int i = 0; i < 4; i++)
        {
            ans[i] = min({a[i], b[i], c[i]});
        }
        return stoi(ans);
    }
};

int main()
{
    Solution s;
    cout << s.generateKey(1, 10, 1000) << endl;
    return 0;
}
