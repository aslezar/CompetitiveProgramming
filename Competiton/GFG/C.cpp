#ifdef LOCAL_RUN

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

// #define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))
#define set_bits __builtin_popcount

#define F first
#define S second
#define PB push_back
#define gcd __gcd
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

constexpr unsigned int mod = 1e9 + 7;
constexpr unsigned int maxn = 1e5 + 4;
constexpr float EPS = numeric_limits<float>::epsilon();
constexpr ll INF = numeric_limits<ll>::max();

class Tree
{
public:
    int val;
    vector<Tree *> childs;
    Tree(int value) : val(value) {}
};

class Solution
{
public:
    pair<int, int> solve(Tree *root, int &ans, unordered_map<Tree *, int> &vis, pair<int, int> &graph)
    {
        vis[root] = 1;

        pair<int, int> cur;
        if (root->val == 2)
            cur.first++;
        if (root->val == 3)
            cur.second++;

        for (auto &child : root->childs)
        {
            if (vis[child] == 0)
            {
                auto t = solve(child, ans, vis, graph);
                cur.first += t.first;
                cur.second += t.second;
            }
        }
        debug(cur, graph);
        if (cur.first > 0 && cur.second > 0 && (graph.first - cur.first) > 0 && (graph.second - cur.second) > 0)
        {
            ans++;
        }
        return cur;
    }
    int splittingEdges(int n, vector<int> &values, vector<vector<int>> &edges)
    {
        vector<Tree *> tree(n, nullptr);
        pair<int, int> cur;
        for (int i = 0; i < n; i++)
        {
            if (values[i] == 2)
                cur.first++;
            if (values[i] == 3)
                cur.second++;
            tree[i] = new Tree(values[i]);
        }
        // debug(cur);
        for (auto &edge : edges)
        {
            tree[edge[0]]->childs.push_back(tree[edge[1]]);
            tree[edge[1]]->childs.push_back(tree[edge[0]]);
        }

        // for (int i = 0; i < n; i++)
        // {
        //     cout << tree[i]->val << ": ";
        //     for (auto &i : tree[i]->childs)
        //     {
        //         cout << i->val << ' ';
        //     }
        //     cout << endl;
        // }

        int ans = 0;
        unordered_map<Tree *, int> vis;
        solve(tree[0], ans, vis, cur);

        // solve(tree, ans);
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    vector<int> values = {3, 2, 2, 3, 1};
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};

    cout << s.splittingEdges(values.size(), values, edges) << endl;

    values = {3, 2, 2, 3, 3, 3, 2};
    edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {4, 6}, {2, 5}};

    cout << s.splittingEdges(values.size(), values, edges);

    cout << endl;

    return 0;
}

#endif