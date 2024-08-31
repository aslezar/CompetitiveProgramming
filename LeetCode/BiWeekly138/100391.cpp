#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minDamage(int power, vector<int> &damage, vector<int> &health)
    {
        for (auto &i : health)
            i = (i + power - 1) / power;

        // for (auto i : health)
        //     cout << i << " ";

        // cout << endl;

        vector<pair<double, int>> d;
        long long sum = 0;
        for (size_t i = 0; i < damage.size(); i++)
        {
            sum += damage[i];
            d.push_back({(double)damage[i] / health[i], i});
        }
        sort(d.begin(), d.end(), greater<pair<double, int>>());

        // for (auto i : d)
            // cout << i.first << " " << i.second << endl;

        long long ans = 0;
        for (size_t i = 0; i < d.size(); i++)
        {
            int index = d[i].second;
            ans += (sum * health[index]);
            sum -= damage[index];
        }
        return ans;
    }
};

int main()
{
    // power = 4, damage = [1,2,3,4], health = [4,5,6,8]
    Solution s;
    vector<int> damage = {1, 2, 3, 4};
    vector<int> health = {4, 5, 6, 8};
    cout << s.minDamage(4, damage, health) << endl;

    // power = 1, damage = [1,1,1,1], health = [1,2,3,4]
    damage = {1, 1, 1, 1};
    health = {1, 2, 3, 4};
    cout << s.minDamage(1, damage, health) << endl;
    return 0;
}
