#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define el << '\n'

const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

int inversions(ll a[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {   
        int t=0;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
                count++;
        }
    }
    return count;
}
int inversion(ll a[], int n, int b)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (i >= b)
            a[i]++;
        for (int j = i + 1; j < n; j++)
        {
            if (j >= b)
                a[j]++;
            if (a[j] < a[i])
                count++;
            if (j >= b)
                a[j]--;
        }
        if (i >= b)
            a[i]--;
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        ll a[] = {8, 4, 2, 1};
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int cinv = inversions(a, n);
        int mininv = cinv;
        for (int i = 1; i < n; i++)
        {
            int t = inversion(a, n, i);
            if (t < mininv)
                mininv = t;
        }

        // cout<<(()?"yes":"no") el;
        cout << cinv - mininv el;
    }
    return 0;
}