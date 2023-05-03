#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long
#define el << '\n'
#define ws << ' '

const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

void rev(string &a)
{
    for (int i = 0; i < n / 2; i++)
    {
        int t1 = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = t1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        string temp;
        cin >> temp;
        rev(temp);
        cout << temp << '\n';
        vector<int> a(n, 0), b(n, 0), c(n, 0);
        for (size_t i = 0; i < n; i++)
        {
            int v = ((temp[i] == '1') ? 1 : 0);
            a[i] = v;
        }
        int s_start = -1;
        cout << temp[0] << '\n';
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                if (s_start == -1)
                {
                    // cout << i << "hello1\n";
                    s_start = i;
                }
            }
            else
            {
                if (s_start != -1)
                {
                    // cout << i << "hello2\n";
                    if (i - s_start > 1)
                    {
                        // cout << i << "hello3\n";
                        if (i < n - 1)
                        {
                            // cout << s_start << ' ' << i << '\n';
                            b[i] = 1;
                            c[s_start] = 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        // cout << i << "hello4\n";
                    }
                }
                else
                {
                    // cout << i << "hello5\n";
                    b[i] = 1;
                    // continue;
                }
                s_start = -1;
            }
        }
        for (int i = s_start; i < n; i++)
        {
            b[i] = 1;
        }

        for (size_t i = 0; i < n; i++)
        {
            cout << b[i];
        }
        cout << '\n';
        for (size_t i = 0; i < n; i++)
        {
            cout << c[i];
        }
        cout << '\n';
    }
    return 0;
}