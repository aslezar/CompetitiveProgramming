#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define el cout << '\n';
// bool valid(const string &s, int start, int length)
// {
//     cout << s << ' ' << start << ' ' << length;
//     bool ans = length == 1 || (s[start] != '0' && (length < 3 || s.substr(start, length) <= "255"));
//     cout << ' ' << ans << '\n';
//     return ans;
//     // return length == 1 || (s[start] != '0' && (length < 3 || s.substr(start, length) <= "255"));
// }

// void helper(const string &s, int startIndex, vector<int> &dots, vector<string> &ans)
// {
//     const int remainingLength = s.length() - startIndex;
//     const int remainingNumberOfIntegers = 4 - dots.size();

//     if (remainingLength > remainingNumberOfIntegers * 3 ||
//         remainingLength < remainingNumberOfIntegers)
//     {
//         return;
//     }
//     if (dots.size() == 3)
//     {
//         if (valid(s, startIndex, remainingLength))
//         {
//             string temp;
//             int last = 0;
//             for (int dot : dots)
//             {
//                 temp.append(s.substr(last, dot));
//                 last += dot;
//                 temp.append(".");
//             }
//             temp.append(s.substr(startIndex));
//             ans.push_back(temp);
//         }
//         return;
//     }
//     for (int curPos = 1; curPos <= 3 && curPos <= remainingLength; ++curPos)
//     {
//         // Append a dot at the current position.
//         dots.push_back(curPos);
//         // Try making all combinations with the remaining string.
//         if (valid(s, startIndex, curPos))
//         {
//             helper(s, startIndex + curPos, dots, ans);
//         }
//         // Backtrack, i.e. remove the dot to try placing it at the next position.
//         dots.pop_back();
//     }
// }

bool isvalid(string &s, int index, int size)
{
    // cout << s;
    // bool ans = (s[0] != 0 && (s.length() < 3 || s <= "255"));
    // cout << ' ' << ans << '\n';
    // return ans;
    return size == 1 || (s[index] != '0' && (size < 3 || s.substr(index, size) <= "255"));
}

void backtrack(string &s, vector<string> &ans, vector<int> &dot, int index)
{
    if (((s.length() - index) > ((4 - dot.size()) * 3)) || ((s.length() - index) < (4 - dot.size())))
        return;
    // if (index >= s.size())
    // {
    //     if (dot == 3)
    //         ans.push_back(seq);
    //     return;
    // }

    if (dot.size() == 3)
    {
        if (isvalid(s, index, s.length() - index))
        {
            string temp;
            int t = 0;
            int z = dot[0];
            for (int i = 0; i < s.length(); i++)
            {
                if (z == 0)
                {
                    temp.push_back('.');
                    z = dot[++t];
                }
                temp.push_back(s[i]);
                z--;
            }

            ans.push_back(temp);
        }
        return;
    }
    for (int i = 1; i <= 3 && i <= (s.length() - index); i++)
    {
        dot.push_back(i);
        if (isvalid(s, index, i))
        {
            backtrack(s, ans, dot, index + i);
        }
        dot.pop_back();
    }

    // if (seq.empty() || (num > -1 && num < 256))
    // {
    //     seq.push_back(s[index]);
    //     backtrack(s, ans, seq, index + 1, dot, num * 10 + int(s[index + 1]));
    //     seq.pop_back();

    //     seq.push_back('.');
    //     seq.push_back(s[index]);
    //     backtrack(s, ans, seq, index + 1, dot + 1, int(s[index + 1]));
    //     seq.pop_back();
    // }
    // seq.push_back(s[index]);
    // backtrack(s, ans, seq, index + 1, dot, -1);
}
vector<string> restoreIpAddresses(string s)
{
    vector<string> ans;
    vector<int> dot;
    // helper(s, 0, dot, ans);
    backtrack(s, ans, dot, 0);
    return ans;
}
int main()
{
    string s = "101023";
    vector<string> ans(restoreIpAddresses(s));
    cout << '[';
    for (int i = 0; i < ans.size(); i++)
        cout << '\"' << ans[i] << "\",";
    cout << "\b]\n";
    return 0;
}