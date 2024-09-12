#include <bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE
#ifdef LOCAL_JUDGE
#include "/algo/debug.h"
#else
#define debug(...) 42
#endif

#define ws << ' '
#define el << '\n'
#define nl cout<<'\n';
#define int long long
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define getbit(x,y) (((x)>>(y))&1ll)
#define turnonandupdate(x,y) x=((x)|(1ll<<y))
#define turnoffandupdate(x,y) x=(x & ~(1ll << (y)))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)(x).size()
#define setbits(x) __builtin_popcount(x)
#define sortall(x) sort(all(x))
#define sortallr(x) sort(rall(x))

const bool multipleTest = 1;
const int mod = 1e9+7;

void run_case(int currTest) {
    int a,b,k;
    cin>>a>>b>>k;
    long double facAByB=((long double)a)/b;
    // if(k==1) {
    //     cout<<"0\n";
    //     return;
    // }
    int firstTimeA=facAByB;
    debug(facAByB,firstTimeA);
    if(k<=firstTimeA) {
        cout<<(k-1)*b el;
        return;
    }
    if((k-(firstTimeA+1))%2==0) {
        cout<<(firstTimeA+(k-(firstTimeA+1))/2)*b el;
        return;
    }
    int nextB=(firstTimeA+(k-(firstTimeA+1)+1)/2);
    nextB-=(firstTimeA+1);
    // debug(firstTimeA,nextB);
    cout<<nextB*b+a el;
}


// void run_case(int currTest) {
//     int a,b,k;
//     cin>>a>>b>>k;
//     long double facAByB=((long double)a)/b;
//     int rep=((int)(facAByB+1))+1;
//     int whichCycle=(k+rep-1)/rep;
//     int firstOfCycle=(whichCycle-1)*(rep-1);
//     int reqAdd=(k+rep-1)%rep;
//     if(k%rep==0) {
//         reqAdd--;
//     }
//     debug(firstOfCycle);
//     firstOfCycle+=reqAdd;
//     debug(facAByB,rep,whichCycle,firstOfCycle);
//     int ans=firstOfCycle*b;
//     if(k%rep==0) {
//         ans+=b;
//     }
//     cout<<ans el;
// }

int32_t main()
{
#ifdef LOCAL_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("log.txt", "w", stderr);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t=1;
    if (multipleTest) cin>>t;
int T=t;
    while(t--)
    {
        run_case(T-t);
    }
    return 0;
}