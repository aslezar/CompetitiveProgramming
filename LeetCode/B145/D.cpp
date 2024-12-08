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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

class DisjointSet
{
    vector<int> parent, rank, size;

public:
    DisjointSet(int n)
    {

        parent.resize(n + 1);

        rank.resize(n + 1);
        for (size_t i = 0; i < parent.size(); i++)
            parent[i] = i;

        size.resize(n + 1, 1);
    }
    int findUltimateParent(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = findUltimateParent(parent[u]);
    }
    // T.C. O(4*alpha) = O(1) alpha is the inverse ackermann function
    void unionByRank(int u, int v)
    {
        int p_u = findUltimateParent(u);
        int p_v = findUltimateParent(v);
        if (p_u == p_v)
            return;
        if (rank[p_v] > rank[p_u])
        {
            parent[p_u] = p_v;
        }
        else if (rank[p_u] > rank[p_v])
        {
            parent[p_v] = p_u;
        }
        else
        {
            parent[p_v] = p_u;
            rank[p_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int p_u = findUltimateParent(u);
        int p_v = findUltimateParent(v);
        if (p_u == p_v)
            return;
        if (size[p_v] > size[p_u])
        {
            // join u to v
            parent[p_u] = p_v;
            size[p_v] += size[p_u];
        }
        else
        {
            // join v to u
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        }
    }
};

class Solution
{
public:
    int countComponents(const vector<int> &n, int threshold)
    {
        int ans = 0;

        set<int> nums(all(n));

        while (nums.size() and *nums.rbegin() > threshold)
            ans++, nums.erase(*nums.rbegin());

        if (nums.size() == 0)
            return ans;

        int maxN = *nums.rbegin();
        DisjointSet ds(maxN);

        unordered_map<int, int> divFind;

        auto tryUnite = [&](const int &a, const int &b)
        {
            if (divFind.count(b))
            {
                if (lcm(a, divFind[b]) <= threshold)
                    ds.unionBySize(a, divFind[b]);
            }
            else
            {
                divFind[b] = a;
            }
        };

        for (auto &&num : nums)
        {
            for (int j = 1; j * j <= num; j++)
            {
                if (num % j == 0)
                {
                    tryUnite(num, j);
                    tryUnite(num, num / j);
                }
            }
        }

        unordered_set<int> s;
        for (auto &&num : nums)
        {
            s.insert(ds.findUltimateParent(num));
        }
        debug(s.size(), ans);
        ans += s.size();
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    cout << s.countComponents({2, 4, 8, 3, 9}, 5) << '\n';
    cout << s.countComponents({2, 4, 8, 3, 9, 12}, 10) << '\n';

    cout << '\n';

    return 0;
}

#endif