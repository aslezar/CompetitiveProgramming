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

class StockSpanner
{
    vector<int> prices;
    stack<int> s;

public:
    StockSpanner() {}

    int next(int price)
    {
        while (!s.empty() && prices[s.top() - 1] <= price)
        {
            s.pop();
        }
        prices.push_back(price);
        int ans = prices.size();
        if (!s.empty())
            ans -= s.top();
        s.push(prices.size());
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

#undef int

#ifdef LOCAL_RUN

int main()
{

    cout << '\n';

    return 0;
}

#endif