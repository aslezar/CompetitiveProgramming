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

const int size_prime = 1e4 + 1;
int spf[size_prime] = {0};
void SieveOfEratosthenes()
{
    for (int i = 2; i * i < size_prime; i++)
    {
        if (spf[i] == 0) // means prime
        {
            for (int j = i * i; j < size_prime; j += i)
            {
                spf[j] = 1;
            }
        }
    }
}
class Solution
{
public:
    // djikstra
    vector<int> dijkstra(int V, vii &adj, int S)
    {
        // T.C. E*log(V)

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);

        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            auto top = pq.top();
            int distance = top.first;
            int node = top.second;
            pq.pop();

            if (dist[node] < distance)
                continue;

            for (auto &it : adj[node])
            {
                int adjNode = it;
                int edgeWg = it;

                if (distance + edgeWg < dist[adjNode])
                {
                    dist[adjNode] = distance + edgeWg;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
    vi numbers(int n)
    {
        vi ans;
        string cn = to_string(n);
        for (int i = 0; i < cn.size(); i++)
        {
            if (cn[i] != '9')
            {

                string s = cn;
                s[i]++;
                ans.push_back(stoi(s));
            }
            if (cn[i] != '0' && (i != 0 || cn[i] != '1'))
            {
                string s = cn;
                s[i]--;
                ans.push_back(stoi(s));
            }
        }
        return ans;
    }
    int minOperations(int n, int m)
    {
        SieveOfEratosthenes();
        spf[1] = 1;
        if (spf[n] == 0 || spf[m] == 0)
            return -1;
        if (n == m)
            return n;
        vii g(1e4 + 1);

        unordered_set<int> vis;
        queue<int> q;
        q.push(n);
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();

            if (vis.find(t) != vis.end())
                continue;
            vis.insert(t);

            vi ns = numbers(t);
            for (auto &&i : ns)
            {
                if (vis.find(i) == vis.end() && spf[i] == 1)
                {
                    q.push(i);
                    g[t].push_back(i);
                    g[i].push_back(t);
                }
            }
        }

        auto dist = dijkstra(1e4 + 1, g, n);

        if (dist[m] == INT_MAX)
            return -1;
        return dist[m] + n;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    cout << s.minOperations(10, 12);

    cout << '\n';

    return 0;
}

#endif