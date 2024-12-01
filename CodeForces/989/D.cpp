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
#define ws << " "

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
constexpr unsigned int mod = 1e9 + 7;

void swapper(int i, int j, vi &v, vector<set<int>> &idx)
{
    idx[v[i]].insert(j);
    idx[v[i]].erase(i);
    idx[v[j]].insert(i);
    idx[v[j]].erase(j);
    swap(v[i], v[j]);
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi nums(n);
    input(nums, n);

    vector<pair<int, int>> moves;

    bool isSorted = is_sorted(nums.begin(), nums.end());
    if (isSorted)
    {
        cout << moves.size() el;
        for (auto [a, b] : moves)
        {
            cout << a + 1 ws << b + 1 el;
        }
        return;
    }
    int l = 0, mid = 0, r = nums.size() - 1;

    set<int> indexof1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            indexof1.insert(i);
        }
    }

    while (mid <= r)
    {
        switch (nums[mid])
        {
        case 0:
            if (nums[l] == 1)
            {
                indexof1.erase(l);
                indexof1.insert(mid);
                swap(nums[l], nums[mid]);
                moves.push_back({l, mid});
            }
            l++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            while (r > mid && nums[r] == 2)
            {
                r--;
            }
            if (r <= mid)
                break;
            if (nums[r] == 1)
            {
                swap(nums[r], nums[mid]);
                moves.push_back({r, mid});
            }
            else if (nums[r] == 0)
            {
                auto index1 = *indexof1.rbegin();
                indexof1.erase(index1);
                auto index0 = r;
                auto index2 = mid;

                if (index1 < index2)
                {
                    swap(nums[index1], nums[index0]);
                    moves.push_back({index1, index0});
                    swap(nums[index2], nums[index0]);
                    moves.push_back({index2, index0});
                    indexof1.insert(index2);
                }
                else if (index1 > index0)
                {
                    swap(nums[index2], nums[index1]);
                    moves.push_back({index2, index1});
                    swap(nums[index2], nums[index0]);
                    moves.push_back({index2, index0});
                    indexof1.insert(index0);
                }
                else
                {
                    swap(nums[index1], nums[index0]);
                    moves.push_back({index1, index0});
                    swap(nums[index2], nums[index0]);
                    moves.push_back({index2, index0});
                    swap(nums[index2], nums[index1]);
                    moves.push_back({index2, index1});
                    indexof1.insert(index1);
                }
            }
            r--;
            break;
        }
    }
    cout << moves.size() el;
    for (auto [a, b] : moves)
    {
        cout << a + 1 ws << b + 1 el;
    }

    debug(nums);
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