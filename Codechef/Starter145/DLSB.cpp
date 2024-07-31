#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> seriesOf0s;
        vector<int> seriesOf1s;

        int i = 0;
        while (i < n)
        {
            if (s[i] == '0')
            {
                int count = 0;
                while (i < n && s[i] == '0')
                {
                    count++;
                    i++;
                }
                seriesOf0s.push_back(count);
            }
            else
            {
                int count = 0;
                while (i < n && s[i] == '1')
                {
                    count++;
                    i++;
                }
                seriesOf1s.push_back(count);
            }
        }

        if (seriesOf0s.size() == 0)
            cout << 0 << endl;
        else if (seriesOf1s.size() == 0)
            cout << min(n, 2) << endl;
        else
        {
            if (seriesOf0s.size() < seriesOf1s.size())
                cout << 0 << endl;
            else if (seriesOf0s.size() == seriesOf1s.size())
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
    return 0;
}
