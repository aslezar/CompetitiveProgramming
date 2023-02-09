#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;

#define el << '\n'
#define ws << ' '
class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        unordered_set<string> alphagrp[26];
        for (auto &idea : ideas)
            alphagrp[idea[0] - 'a'].insert(idea.substr(1));
        long long ans = 0;
        for (int i = 0; i < 25; ++i)
        {
            for (int j = i + 1; j < 26; ++j)
            {
                int num = 0;
                for (auto &idea : alphagrp[i])
                {
                    if (alphagrp[j].count(idea))
                    {
                        num++;
                    }
                }
                ans += 2LL * (alphagrp[i].size() - num) * (alphagrp[j].size() - num);
            }
        }
        return ans;
    }
};
// class Solution
// {
// public:
//     long long distinctNames(vector<string> &ideas)
//     {
//         if (ideas.size() == 1)
//             return 0;
//         long long ans = 0;
//         sort(ideas.begin(), ideas.end());
//         map<char, int> m;
//         for (int i = ideas.size() - 1; i >= 0; i--)
//         {
//             m[ideas[i][0]] = i;
//         }

//         for (int i = 0; i < ideas.size() - 1; i++)
//         {
//             for (int j = i + 1; j < ideas.size(); j++)
//             {
//                 if (ideas[i][0] == ideas[j][0])
//                     continue;
//                 string a = ideas[i];
//                 string b = ideas[j];
//                 char temp = a[0];
//                 a[0] = b[0];
//                 b[0] = temp;
//                 auto it = find(ideas.begin() + m[ideas[j][0]], ideas.end() - m.size() + m[ideas[j][0]], a);
//                 auto it2 = find(ideas.begin() + m[ideas[i][0]], ideas.end() - m.size() + m[ideas[i][0]], b);
//                 if (it == ideas.end() - m.size() + m[ideas[j][0]] && it2 == ideas.end() - m.size() + m[ideas[i][0]])
//                 {
//                     ans += 2;
//                 }
//             }
//         }
//         return ans;
//     }
// };
int main()
{

    return 0;
}