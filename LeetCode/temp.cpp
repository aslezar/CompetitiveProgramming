#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void traversal(int root, vector<vector<int>> &road, vector<bool> &visited, int &ans)
    {
        visited[root] = true;
        for (auto &&i : road[root])
        {
            if (visited[abs(i)])
                continue;
            if (i < 0)
            {
                ans++;
                traversal(-i, road, visited, ans);
            }
            else
            {
                traversal(i, road, visited, ans);
            }
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
        for (auto &&i : road)
        {
            for (auto &&j : i)
            {
                cout << j ws;
            }
            cout el;
        }

        int ans = 0;
        vector<bool> visited(n, false);
        traversal(0, road, visited, ans);
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
