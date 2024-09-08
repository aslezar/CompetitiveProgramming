#ifdef LOCAL_RUN

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int parentOf(int u)
    {
        assert(u < parent.size());

        if (parent[u] == u)
            return u;
        return parent[u] = parentOf(parent[u]);
    }
    void unionR(int u, int v)
    {
        assert(u < parent.size());
        assert(v < parent.size());

        int pu = parentOf(u);
        int pv = parentOf(v);
        if (pu == pv)
            return;
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        DisjointSet ds(accounts.size());
        unordered_map<string, int> emailToAcc;

        for (int acc = 0; acc < accounts.size(); acc++)
        {
            auto &a = accounts[acc];

            for (int i = 1; i < a.size(); i++)
            {
                string &mail = a[i];

                if (emailToAcc.find(mail) == emailToAcc.end())
                {
                    emailToAcc[mail] = acc;
                }
                else
                {
                    ds.unionR(acc, emailToAcc[mail]);
                }
            }
        }

        unordered_map<int, set<string>> mergedAcc;

        for (auto &i : emailToAcc)
        {
            auto &email = i.first;
            auto &acc = i.second;

            int parent = ds.parentOf(acc);
            mergedAcc[parent].insert(email);
        }

        vector<vector<string>> ans;
        for (auto &i : mergedAcc)
        {
            auto &acc = i.first;
            auto &emails = i.second;

            vector<string> account;
            account.push_back(accounts[acc][0]);
            account.insert(account.end(), emails.begin(), emails.end());
            ans.push_back(account);
        }

        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    // n = 4
    // accounts [ ] =
    // [["John","johnsmith@mail.com","john_newyork@mail.com"],
    // ["John","johnsmith@mail.com","john00@mail.com"],
    // ["Mary","mary@mail.com"],
    // ["John","johnnybravo@mail.com"]]
    Solution s;
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                       {"John", "johnsmith@mail.com", "john00@mail.com"},
                                       {"Mary", "mary@mail.com"},
                                       {"John", "johnnybravo@mail.com"}};
    auto ans = s.accountsMerge(accounts);
    debug(ans);
    cout << endl;

    return 0;
}

#endif