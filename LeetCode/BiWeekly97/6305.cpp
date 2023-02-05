#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

bool fn(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.first > b.first;
}
class Solution
{
public:
    int maximizeWin(vector<int> &prizePositions, int k)
    {
        map<int, int> f;
        // unordered_map<int, pair<int, int>> ans;
        vector<pair<int, pair<int, int>>> ans;

        for (int i = 0; i < prizePositions.size(); i++)
        {
            f[prizePositions[i]]++;
        }
        for (int i = f.begin()->first; i <= f.end()->first; i++)
        {
            int t = i;
            int temp = 0;
            for (int j = 0; j <= k; j++)
            {
                if (f.find(t) != f.end())
                {
                    temp += f[t];
                }
                t++;
            }
            ans.push_back({temp, {i, i + k}});
        }
        sort(ans.begin(), ans.end(), fn);
        int finalans = ans[0].first + ans[1].first;
        int a, b, c, d;
        a = ans[0].second.first;
        b = ans[0].second.second;
        c = ans[1].second.first;
        d = ans[1].second.second;
        if()
        for (int i = 0; i < count; i++)
        {
        }

        // cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n';
        return finalans;
    }
};