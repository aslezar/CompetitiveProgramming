#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_RUN
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
#define input(vec, n)           \
    for (int i = 0; i < n; i++) \
        std::cin >> vec[i];

#define el << endl;
#define ws << " ";

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
constexpr unsigned int mod = 1e9 + 7;

class MedianFinder
{
    set<int> left;
    set<int> right;
    int sum = 0;

public:
    MedianFinder() {}

    void removeNum(int num)
    {
        if (right.find(num) != right.end())
        {
            right.erase(right.find(num));
        }
        else if (left.find(num) != left.end())
        {
            left.erase(left.find(num));
            sum -= num;
        }
    }

    void addNum(int num)
    {

        left.insert(num);
        sum += num;

        // Make sure left <= right
        if ((int)left.size() > 0 && (int)right.size() > 0 && *left.rbegin() > *right.begin())
        {
            right.insert(*left.rbegin());
            sum -= (*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        }

        //  Make sure left donot have more than 1 extra element than right
        if ((int)left.size() - (int)right.size() > 1)
        {
            // right.push(left.top());
            // left.pop();
            right.insert(*left.rbegin());
            sum -= (*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        }

        //  Make sure right donot have more elements than left
        if ((int)right.size() - (int)left.size() > 0)
        {
            // left.push(right.top());
            // right.pop();
            left.insert(*right.begin());
            sum += (*right.begin());
            right.erase(right.find(*right.begin()));
        }
    }

    int findMedian()
    {
        debug(left, right);
        int n = left.size();
        int m = right.size();
        if (n + m == 0)
            return 0;
        if ((n + m) % 2 == 0)
        {
            return 2 * sum;
        }
        return 2 * sum - *left.rbegin();
    }
};

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    ll k = 0;
    cin >> k;

    vi v(n);
    input(v, n);

    MedianFinder m;
    for (int i = k; i < n; i++)
    {
        m.addNum(v[i]);
    }
    int ans = m.findMedian();
    for (int i = 0; i + k < n; i++)
    {
        m.removeNum(v[i + k]);
        m.addNum(v[i]);
        ans = max(ans, m.findMedian());
    }
    cout << ans << '\n';
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}