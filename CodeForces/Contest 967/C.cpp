#include <bits/stdc++.h>
using namespace std;

#define ll long long
const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

class Soln
{
public:
    vector<vector<int>> save;
    vector<vector<int>> tree;
    int edges;
    int n;

    Soln(int n)
    {
        this->save = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        this->tree = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        this->edges = 0;
        this->n = n;
    }
    void printAns()
    {
        cout << "!";
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (tree[i][j] == 1)
                {
                    cout << ' ' << i << ' ' << j << endl;
                }
            }
        }
    }
    void link(int a, int b)
    {
        assert(a > 0 && b > 0);
        assert(a <= n && b <= n);
        assert(a != b);
        if (tree[a][b] == 1)
            return;
        tree[a][b] = 1;
        tree[b][a] = 1;
        edges++;
    }
    int ask(int a, int b)
    {
        int size = save.size();
        assert(a != b);
        assert(a > 0 && b > 0);
        assert(a < size && b < size);

        if (save[a][b] != -1)
            return save[a][b];

        cout << "? " << a << ' ' << b << endl;
        int res;
        cin >> res;
        if (res == -1)
            exit(0);
        return res;
    }
    void resolver(int left, int right)
    {
        if (edges == n - 1)
            return;

        int res = ask(left, right);
        if (left == res || right == res)
        {
            link(left, right);
            return;
        }
        int res2 = ask(right, left);
        if (res == res2)
        {
            // odd length
            resolver(left, res);
            resolver(res, right);
        }
        else
        {
            // even length
            link(res, res2);
            if (edges == n - 1)
                return;
            resolver(left, res);
            resolver(res2, right);
        }
    }
    void solve()
    {
        for (int start = 1; start <= n; start++)
        {
            for (int i = i + 1; i <= n; i++)
            {
                if (i == start)
                    continue;
                int res = ask(start, i);
                resolver(start, i);
                if (edges == n - 1)
                {
                    printAns();
                    goto nextCase;
                }
            }

        nextCase:
            return;
        }
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
        // vector<vector<int>> save(n + 1, vector<int>(n + 1, -1));
        // vector<vector<int>> tree(n + 1, vector<int>(n + 1, -1));
        Soln soln(n);
        soln.solve();
    }
    return 0;
}