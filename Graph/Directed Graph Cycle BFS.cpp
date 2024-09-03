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
constexpr unsigned int maxn = 1e5 + 4;
constexpr float EPS = numeric_limits<float>::epsilon();
constexpr ll INF = numeric_limits<ll>::max();

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
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
        return ans.size() != V;
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