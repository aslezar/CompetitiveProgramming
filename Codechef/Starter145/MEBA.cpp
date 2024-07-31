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
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            freq[temp]++;
        }
        if (freq.size() == 1)
        {

            cout << "YES" << endl;
        }
        else if (freq.size() == 2)
        {
            if (freq.count(0))
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
