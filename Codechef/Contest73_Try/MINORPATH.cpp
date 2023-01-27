#include <iostream>
#include <climits>
using namespace std;

#define ll long long
#define el << '\n'
#define ws << ' ' 0

const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

int backtrack(int a[], int n, int start, int prevcost)
{
    if (start == n)
        return 0;
    if (a[start] == 0)
        return -1;

    int minimum = min(a[start] + start, n);
    int mincost = prevcost;
    for (int i = start + 1; i <= minimum; i++)
    {
        // i+a[start]
        int temp = backtrack(a, n, i, mincost);

        // if (mincost != -1 && temp < ans)
        // {
        //     return temp;
        // }
    }
    return mincost;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        int a[500000];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int cost[500000] = {0};
        for (int i = n - 2; i >= 0; i--)
        {
            cost[i] = a[i] ^ cost[i + 1];
        }

        // cout<<(()?"YES":"NO") el;
        cout << backtrack(a, n, 0, INT_MAX) el;
    }
    return 0;
}