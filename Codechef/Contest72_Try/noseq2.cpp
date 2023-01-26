#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        long long n, k, s;
        cin >> n >> k >> s;
        bool flag = 0;
        vector<int> ans;
        while (s > 0)
        {
            if (s % k == 0 || s % k == 1)
            {
                ans.push_back(s % k);
            }
            else if (s % k == k - 1)
            {
                ans.push_back(-1);
                s += 1;
            }
            else
            {
                flag = 1;
                break;
            }
            s = s / k;
        }

        if (ans.size() > n)
            flag = 1;
        else if (ans.size() < n)
        {
            int t = n - ans.size();
            while (t--)
                ans.push_back(0);
        }
        if (flag == 1)
            cout << -2 << endl;
        else
        {
            for (auto i : ans)
                cout << i << ' ';
            cout << endl;
        }
        t--;
    }
    return 0;
}
