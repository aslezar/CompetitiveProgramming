#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int ans = w;
        int size = profits.size();
        vector<array<int, 2>> a;
        for (int i = 0; i < size; i++)
        {
            a.push_back({capital[i], profits[i]});
        }
        sort(a.begin(), a.end(), [](auto m, auto n)
             { return m[0] < n[0]; });
        for (auto &&i : a)
        {
            cout << i[0] << ' ' << i[1] << '\n';
        }
        cout << "Hello" << '\n';
        vector<array<int, 2>> b;
        while (k--)
        {
            for (int i = b.size(); i < size; i++)
            {
                if (a[i][0] > ans)
                    break;
                b.push_back({a[i][1], a[i][0]});
            }
            if (b.size() == 0)
                continue;
            sort(b.begin(), b.end(), [](auto m, auto n)
                 { return m[0] > n[0]; });
            for (auto &&i : b)
            {
                cout << i[0] << ' ' << i[1] << '\n';
            }
            cout << "Done\n";
            ans += b[0][0];

            b[0][1] = 0;
            b[0][0] = 0;
            cout << ans << '\n';
        }
        return ans;
    }
};
class Solution2
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++)
        {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> q;
        int ptr = 0;
        for (int i = 0; i < k; i++)
        {
            while (ptr < n && projects[ptr].first <= w)
            {
                q.push(projects[ptr++].second);
            }
            if (q.empty())
            {
                break;
            }
            w += q.top();
            q.pop();
        }
        return w;
    }
};

int main()
{

    return 0;
}