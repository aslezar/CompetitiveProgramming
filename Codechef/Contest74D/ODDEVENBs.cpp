#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define el << '\n'

const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 4;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        int a[n];
        int no=0;
        bool ans=0;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            if(!a[i])
                no++;
        }
        // cout<<n<<' '<<no<<'\n';
        if(no%2==0)
        {
            ans=1;
        }
        cout<<(ans?"yes":"no") el;
    }
    return 0;
}