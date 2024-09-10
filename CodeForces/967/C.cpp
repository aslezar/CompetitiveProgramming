#include <bits/stdc++.h>
using namespace std;

#define ll long long
const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

class Soln
{
public:
    vector<int> tree;
    int n;

    Soln(int n)
    {
        this->n = n;
        this->tree.resize(n + 1);
    }
    void printAns()
    {
        cout << "!";
        for (int i = 2; i <= n; i++)
        {
            cout << ' ' << tree[i] << ' ' << i;
        }
        cout << endl;
    }
    void link(int a, int b)
    {
        tree[a] = b;
    }
    int ask(int a, int b)
    {
        cout << "? " << a << ' ' << b << endl;
        int res;
        cin >> res;
        if (res == -1)
            exit(0);
        return res;
    }
    void solve()
    {
        for (int i = 2; i <= n; i++)
        {
            int par = 1;
            while (true)
            {
                int res = ask(i, par);
                if (res == i)
                    break;
                else
                    par = res;
            }
            link(i, par);
        }
        printAns();
    }
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        Soln soln(n);
        soln.solve();
    }
    return 0;
}