#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    void traversal(int root, vector<vector<int>> &road, vector<int> &v, int &ans)
    {
        v[root] = 1;
        for (auto &&i : road[root])
        {
            if (v[abs(i)])
                continue;
            if (i > 0)
                ans++;
            traversal(abs(i), road, v, ans);
        }
    }
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> road(n);
        for (auto &&i : connections)
        {
            road[i[0]].push_back(i[1]);
            road[i[1]].push_back(-i[0]);
        }
        int ans = 0;
        vector<int> v(n, 0);
        traversal(0, road, v, ans);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    int n = 6;
    int ans = s.minReorder(n, connections);
    cout << ans << endl;
    return 0;
}