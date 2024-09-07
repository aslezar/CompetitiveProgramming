/*
    Floyd Warshall Algorithm
    It is used to find the shortest path for all nodes to all nodes

    we traverse all nodes and try to get to other nodes via the current node
    it is brute force approach

    Time Complexity: O(N^3)
    Space Complexity: O(N^2)
*/

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
    void shortest_distance(vector<vector<int>> &matrix)
    {
        // T.C. O(N^3)
        int n = matrix.size();
        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][via] != -1 && matrix[via][j] != -1)
                    {
                        matrix[i][j] = min((matrix[i][j] == -1 ? (int)1e9 : matrix[i][j]), matrix[i][via] + matrix[via][j]);
                    }
                }
            }
        }

        // to detect a negatice cycle
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][i] != 0)
            {
                cout << "Negative Cycle\n";
            }
        }

        // Djasksta Algo is better than floyd warshall, but only problem is that it does not work for negative edge weight
        // For same problem Djskastra will work in N*(E*logV) if weights are postive
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