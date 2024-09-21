#include <bits/stdc++.h>

using namespace std;
#define Fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define cinn(x)                        \
    for (int i = 0; i < x.size(); i++) \
        cin >> x[i];
#define printa(x)                      \
    for (int i = 0; i < x.size(); i++) \
        cout << x[i] << " ";
#define LL long long
#define pb push_back
#define ppb pop_back
#define MP make_pair
#define ff first
#define ss second
#define sf scanf
#define pf printf
#define SQR(x) ((x) * (x))
#define loop(i, y) for (int i = 0; i < int(y); i++)
#define FOR(i, x, y) for (int i = int(x); i <= int(y); i++)
#define ROF(i, x, y) for (int i = int(x); i >= int(y); i--)
#define sz(c) int(c.size())
#define clr(x, y) memset(x, y, sizeof(x))
#define si(x) scanf("%d", &x)
#define sii(x, y) scanf("%d %d", &x, &y)
#define siii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sl(x) scanf("%lld", &x)
#define sll(x, y) scanf("%lld %lld", &x, &y)
#define slll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))

template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};

#ifdef VAMP
#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " = " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " = " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define dbg(...)
#endif

template <class T, class L>
inline T bigMod(T p, T e, L M)
{
    LL ret = 1 % M;
    for (; e > 0; e >>= 1)
    {
        if (e & 1)
            ret = (ret * p) % M;
        p = ((LL)p * p) % M;
    }
    return (L)ret;
}

/// Constants
#define MAX 200005
#define MOD 1000000007
#define eps 1e-9
#define INF 0x3f3f3f3f3f3f3f3f // 4,557,430,888,798,830,399
#define inf 0x3f3f3f3f         // 1,061,109,567
#define PI acos(-1.0)          // 3.1415926535897932
#define VT int

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    ll l1 = *min_element(all(a)), r1 = 2e17;
    ll mn = l1;
    while (l1 <= r1)
    {
        ll mid = (l1 + r1) >> 1;

        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= mid)
            {
                sum += a[i] - mid;
            }
            else
            {
                sum -= mid - a[i];
            }

            if (sum < 0)
            {
                break;
            }
        }

        if (sum >= 0)
        {
            mn = mid;
            l1 = mid + 1;
        }
        else
        {
            r1 = mid - 1;
        }
    }

    l1 = mn, r1 = *max_element(all(a));
    ll mx = r1;
    while (l1 <= r1)
    {
        ll mid = (l1 + r1) >> 1;

        ll sum = 0;
        ll emergency = 0;
        vector<ll> b(n);
        for (int i = 0; i < n; i++)
        {
            b[i] = a[i];
        }

        int f = 1;

        for (int i = 0; i < n; i++)
        {
            if (b[i] > mid)
            {
                emergency += (b[i] - mid);
                b[i] -= emergency;
                sum += mid - mn;
            }
            else
            {
                ll g = min(mid - b[i], emergency);
                emergency -= g;
                b[i] += g;

                sum += b[i] - mn;
            }

            if (sum < 0)
            {
                break;
            }
        }

        if (sum >= 0 && emergency == 0)
        {
            mx = mid;
            r1 = mid - 1;
        }
        else
        {
            l1 = mid + 1;
        }
    }
    cout << (mx - mn) << "\n";
}

int main()
{
    int t = 1;

    Fast_io;

    cin >> t;
    int c = 1;
    while (t--)
    {
        // cout << "Case " << c++ << ": ";
        solve();
    }
    return 0;
}
