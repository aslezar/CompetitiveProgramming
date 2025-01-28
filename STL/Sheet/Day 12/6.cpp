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

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (auto &num : nums)
        {
            freq[num]++;
        }

        struct Number
        {
            int freq;
            int value;
        };
        function<bool(Number, Number)> comp = [](Number a, Number b) -> bool
        {
            return a.freq > b.freq;
        };
        priority_queue<Number, vector<Number>, decltype(comp)> pq(comp);
        for (auto &i : freq)
        {
            pq.push({i.second, i.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().value);
            pq.pop();
        }
        return ans;

        // auto comp = [&](int a, int b) { return freq[a] > freq[b]; };
        // priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        // for (auto& i : freq) {
        //     pq.push(i.first);
        //     if (pq.size() > k)
        //         pq.pop();
        // }
        // vector<int> ans;
        // while (!pq.empty()) {
        //     ans.push_back(pq.top());
        //     pq.pop();
        // }
        // return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    cout << '\n';

    return 0;
}

#endif