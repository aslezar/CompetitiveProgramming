//1061. Lexicographically Smallest Equivalent String
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define el cout << '\n';
string smallestEquivalentString(string s1, string s2, string baseStr)
{
    char a[30] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < s1.length(); i++)
    {
        char x = min(a[s1[i] - 'a'], a[s2[i] - 'a']);
        char y = max(a[s1[i] - 'a'], a[s2[i] - 'a']);
        // cout << '\n'
        //      << x << '\n';
        a[s1[i] % 'a'] = x;
        a[s2[i] % 'a'] = x;
        for (int i = 0; i < 26; i++)
        {
            if (a[i] == y)
                a[i] = x;
        }
        // for (int i = 0; i < 26; i++)
        // {
        //     cout << a[i] << ' ';
        // }
        // el;
    }
    string ans;
    for (int i = 0; i < baseStr.length(); i++)
    {
        ans += a[baseStr[i] % 'a'];
    }
    // for (int i = 0; i < 26; i++)
    // {
    //     cout << char('a' + i) << ' ' << a[i] << '\n';
    // }
    // el
    return ans;
}
int main()
{
    cout << smallestEquivalentString("leetcode", "programs", "sourcecode");
    return 0;
}