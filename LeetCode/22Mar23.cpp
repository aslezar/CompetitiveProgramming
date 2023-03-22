#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> road[n + 1];
        for (auto &&i : roads)
        {
            road[i[0]].push_back({i[1], i[2]});
            road[i[1]].push_back({i[0], i[2]});
        }
        vector<bool> v(n + 1, 0);
        queue<int> q;
        q.push(1);
        v[1] = 1;
        int ans = INT_MAX;
        while (!q.empty())
        {
            for (auto &&i : road[q.front()])
            {
                if (i.second < ans)
                    ans = i.second;
                if (v[i.first] == 0)
                {
                    v[i.first] = 1;
                    q.push(i.first);
                }
            }
            q.pop();
        }
        return ans;
    }
};
int main()
{

    return 0;
}