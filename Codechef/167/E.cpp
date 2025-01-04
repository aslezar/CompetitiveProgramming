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

// bool verify(vii &v)
// {
//     int n = v.size();

//     int s1 = 0;
//     for (int i = 0; i < n; i++)
//     {
//         s1 += v[i][i];
//     }
//     int s2 = 0;
//     for (int i = 0; i < n; i++)
//     {
//         s2 += v[i][n - i - 1];
//     }
//     int sumRow = 0;
//     int sumCol = 0;
//     for (int j = 0; j < n; j++)
//     {
//         sumRow += v[0][j];
//         sumCol += v[j][0];
//     }

//     for (int i = 1; i < n; i++)
//     {
//         int sumRow1 = 0;
//         int sumCol1 = 0;
//         for (int j = 0; j < n; j++)
//         {
//             sumRow1 += v[i][j];
//             sumCol1 += v[j][i];
//         }
//         if (sumRow + sumRow1 != s1 + s2)
//         {
//             return false;
//         }
//         if (sumCol + sumCol1 != s1 + s2)
//         {
//             return false;
//         }
//         swap(sumRow, sumRow1);
//         swap(sumCol, sumCol1);
//     }
//     return true;
// }

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vii v(n, vi(n, 0));

    if ((n / 2) % 2 == 1)
    {
        int start = n / 2;
        for (int i = 0; i < n; i++)
        {
            v[i][0] = ((start - i + n) % n) + 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                v[i][j] = ((v[i][0] + j - 1) % n) + 1;
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i += 2)
        {
            int no = (i + n) % n + 1;
            int j = 0;
            while (j < n && no >= 1)
            {
                v[i][j] = no;
                no--;
                j++;
            }
            no = n;
            while (j < n)
            {
                v[i][j] = no;
                no--;
                j++;
            }
            v[i + 1] = v[i];
            reverse(all(v[i + 1]));
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
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
    // for (int i = 2; i <= 500; i = i + 2)
    // {
    //     solve(i);
    // }
    return 0;
}