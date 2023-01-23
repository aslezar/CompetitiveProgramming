#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define el << '\n'
#define ws << ' '

int findJudge(int n, vector<vector<int>> &trust)
{
    map<int, int> ismenhihonachaye;
    map<int, int> ismehonachaye;
    if (n == 1)
        return 1;

    for (int i = 0; i < trust.size(); i++)
    {
        ismenhihonachaye[trust[i][0]]++;
        ismehonachaye[trust[i][1]]++;
    }
    for (int i = 0; i < n; i++)
        if (ismenhihonachaye.find(i + 1) == ismenhihonachaye.end())
        {
            auto it = ismehonachaye.find(i + 1);
            if (it != ismehonachaye.end())
                if (it->second == n - 1)
                    return it->first;
        }
    return -1;
}
int main()
{
    vector<vector<int>> v({{1, 3}, {2, 3}, {3, 1}});
    cout << findJudge(3, v) el;

    return 0;
}