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

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        string nation;
        cin >> n >> nation;
        ll ans = 0;
        string temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp == "CONTEST_WON")
            {
                ans += 300;
                int rank = 0;
                cin >> rank;
                if (rank <= 20)
                    ans += (20 - rank);
            }
            else if (temp == "TOP_CONTRIBUTOR")
            {
                ans += 300;
            }
            else if (temp == "BUG_FOUND")
            {
                int severity = 0;
                cin >> severity;
                ans += severity;
            }
            else if (temp == "CONTEST_HOSTED")
            {
                ans += 50;
            }
        }
        if (nation == "INDIAN")
            ans /= 200;
        else
            ans /= 400;

        // cout<<(()?"YES":"NO") el;
        cout << ans el;
    }
    return 0;
}