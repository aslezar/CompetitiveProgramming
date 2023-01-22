#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long
#define el << '\n'
#define ws << ' '

const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

bool comp(int a, int b)
{
    return a > b;
}
ll input(ll a = 0)
{
    cin >> a;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);

    ll n = 0;
    cin >> n;
    ll ans = 0;
    vector<ll> a;
    for (int i = 0; i < n; i++)
    {
        a.push_back(input());
    }
    sort(a.begin(), a.end(), comp);
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, a[i] * (i + 1));
    }

    // cout<<(()?"YES":"NO") el;
    cout << ans el;
    return 0;
}