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
int maximizeWin(vector<int> &prizePositions, int k)
{
    map<int, int> f;
    // unordered_map<int, pair<int, int>> ans;
    vector<pair<int, pair<int, int>>> ans;

    for (int i = 0; i < prizePositions.size(); i++)
    {
        f[prizePositions[i]]++;
    }
    // for (auto &&i : f)
    // {
    //     cout << i.first ws << i.second el;
    // }
    // cout << f.rbegin()->first el;
    for (int i = f.begin()->first; i + k <= f.rbegin()->first; i++)
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
    for (auto &&i : ans)
    {
        cout << i.first ws << i.second.first ws << i.second.second el;
    }
    cout el;

    sort(ans.begin(), ans.end(), fn);
    // for (auto &&i : ans)
    // {
    //     cout << i.first ws << i.second.first ws << i.second.second el;
    // }
    int finalans = ans[0].first + ans[1].first;
    int a, b, c, d;
    a = ans[0].second.first;
    b = ans[0].second.second;
    c = ans[1].second.first;
    d = ans[1].second.second;
    cout << a ws << b ws << c ws << d;
    if (!(c > b || a > d))
    {
        finalans = 0;
        for (int i = a; i <= d; i++)
        {
            if (f.find(i) != f.end())
            {
                finalans += f[i];
                cout << f[i] ws;
            }
        }
    }
    cout el;
    return finalans;
}
int main()
{
    vector<int> a = {1, 1, 2, 2, 3, 3, 5};
    cout << maximizeWin(a, 2);
    return 0;
}