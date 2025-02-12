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

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;
    int m = 0;
    cin >> m;

    vi A(n);
    input(A, n);

    vi B(m), BB;
    input(B, m);

    if (m == 1)
    {
        for (int i = 0; i + m <= n; i++)
        {
            if (A[i] > B[0])
            {
                A[i] = B[0];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << ' ';
        }
        cout << '\n';
        return;
    }

    // index of min ele in B
    int minB = min_element(all(B)) - B.begin();
    for (int i = 0; i < m; i++)
    {
        BB.push_back(B[(minB + i) % m]);
    }
    debug(BB);
    B = BB;

    for (int i = 0; i + m <= n; i++)
    {
        if (A[i] > BB[0])
        {
            for (; i + m <= n; i++)
            {
                A[i] = BB[0];
            }
            for (int j = 1; j < m; j++)
            {
                A[i++] = BB[j];
            }
            break;
        }
    }
    bool change = false;
    for (int i = 0; i < m; i++)
    {
        debug(A[n - m + i], BB[i]);
        if (A[n - m + i] > BB[i])
        {
            change = true;
            break;
        }
        if (A[n - m + i] < BB[i])
        {
            break;
        }
    }
    if (change)
    {
        for (int j = 0; j < m; j++)
        {
            A[n - m + j] = BB[j];
        }
    }
    debug(change);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << ' ';
    }
    cout << '\n';
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