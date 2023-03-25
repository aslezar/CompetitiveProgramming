#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

#define ll long long
#define el << '\n'
#define ws << ' '

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    int t = 0;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        if (n.size() == 1)
        {
            cout << 'a' el;
            break;
        }
        map<char, char> m;
        vector<bool> visit(26, 0);
        for (int i = 0; i < n.size(); i++)
        {
            if (m[n[i]] != 0)
            {
                n[i] = m[n[i]];
            }
            else
            {
                for (int j = 0; j < 26; j++)
                {
                    if (visit[j] == 0)
                    {
                        if (j != n[i] - 'a')
                        {
                            m[n[i]] = j + 'a';
                            n[i] = m[n[i]];
                            visit[j] = 1;
                            break;
                        }
                    }
                }
            }
        }
        cout << n el;
    }
    return 0;
}