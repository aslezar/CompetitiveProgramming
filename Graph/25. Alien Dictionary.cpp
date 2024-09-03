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

class Solution
{
public:
    string findOrder(string dict[], int n, int k)
    {

        // follow-up
        // what if dict is not correct
        // two cases when dict is wrong are
        // 1. dict first word is greater than next word like abcd abc
        // 2. if there is cyclic dependency like ab ba ac

        vector<vi> adj(k);
        for (int i = 1; i < n; i++)
        {
            string &w1 = dict[i - 1];
            string &w2 = dict[i];

            int index = 0;

            while (index < int(min(w1.length(), w2.length())) && w1[index] == w2[index])
            {
                index++;
            }
            debug(w1, w2, index);

            if (index == int(min(w1.length(), w2.length())))
                continue;
            else
                adj[w1[index] - 'a'].push_back(w2[index] - 'a');
        }
        debug(adj);

        vi indegree(k);
        for (int i = 0; i < k; i++)
        {
            for (auto &n : adj[i])
            {
                indegree[n]++;
            }
        }

        string ans;
        queue<int> q;
        for (int i = 0; i < k; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            ans += front + 'a';

            for (auto &n : adj[front])
            {
                indegree[n]--;
                if (indegree[n] == 0)
                {
                    q.push(n);
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
    Solution s;
    // n = 5, k = 4, dict = {"baa","abcd","abca","cab","cad"}

    int n = 5, k = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    cout << s.findOrder(dict, n, k) << endl;
    cout << endl;

    return 0;
}

#endif