#ifdef LOCAL_RUN

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long
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

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // T.C. E*logE

        // To get the edges of minimum spanning tree, you also had to store the parent of the node from where it pushed into the queue

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(V, 0);

        pq.push({0, 0});
        int sum = 0;

        // E
        while (!pq.empty())
        {
            // log E
            auto top = pq.top();
            pq.pop();

            int edWg = top.first;
            int node = top.second;

            if (vis[node] == 1)
            {
                continue; // Skip this node, already visited
            }
            vis[node] = 1;
            sum += edWg;

            // E *logE
            for (auto &edge : adj[node])
            {
                int edgeNode = edge[0];
                int edgeWg = edge[1];

                if (vis[edgeNode] == 0)
                {
                    pq.push({edgeWg, edgeNode});
                }
            }
        }
        // in total : ElogE+ElogE = ElogE
        return sum;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    // cout << s.checkTwoChessboards("a1", "b2") << endl;
    cout << endl;

    return 0;
}

#endif