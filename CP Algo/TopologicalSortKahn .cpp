#ifdef LOCAL_RUN

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

class Solution
{

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vvi &adj)
    {
        // T.C. O(V + E)
        // S.C. O(2V) = O(V)
        vi ans;

        // O(E)
        vi indegre(V);
        FOR(i, 0, V - 1)
        {
            for (auto &j : adj[i])
            {
                indegre[j]++;
            }
        }
        debug(indegre);

        // Space (N)
        queue<int> q;

        // O(V)
        FOR(i, 0, V - 1)
        {
            if (indegre[i] == 0)
            {
                q.push(i);
            }
        }

        // O(2*E)
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto &i : adj[front])
            {
                indegre[i]--;
                if (indegre[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    return 0;
}

#endif