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

template <typename T>
class SegmentTree
{
    vector<T> seg;

    // Change this function
    T combine(const T &a, const T &b)
    {
        return __gcd(a, b);
    }

    void build(const vi &arr, int index, int l, int r)
    {
        if (l == r)
        {
            seg[index] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(arr, 2 * index + 1, l, mid);
        build(arr, 2 * index + 2, mid + 1, r);
        seg[index] = combine(seg[2 * index + 1], seg[2 * index + 2]);
    }

    T query_help(int index, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
            return 0;
        if (l >= ql && r <= qr)
            return seg[index];
        int mid = l + (r - l) / 2;
        T left = query_help(2 * index + 1, l, mid, ql, qr);
        T right = query_help(2 * index + 2, mid + 1, r, ql, qr);
        return combine(left, right);
    }

    T update_help(int index, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            seg[index] = val;
            return val;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid)
        {
            update_help(2 * index + 1, l, mid, pos, val);
        }
        else
        {
            update_help(2 * index + 2, mid + 1, r, pos, val);
        }
        seg[index] = combine(seg[2 * index + 1], seg[2 * index + 2]);
        return seg[index];
    }

public:
    SegmentTree(const vector<T> &arr)
    {
        size_t size = arr.size();
        seg.resize(4 * size);
        build(arr, 0, 0, size - 1);
    }

    T query(int l, int r)
    {
        return query_help(0, 0, seg.size() / 4 - 1, l, r);
    }

    T update(int pos, int val)
    {
        return update_help(0, 0, seg.size() / 4 - 1, pos, val);
    }
};

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    int q = 0;
    cin >> q;

    vi v(n);
    input(v, n);

    if (n == 1)
    {
        int l, r;
        for (int i = 0; i < q; i++)
        {
            cin >> l >> r;
            cout << 0 << ' ';
        }
        cout << '\n';
        return;
    }

    vi diff;
    for (int i = 1; i < n; i++)
    {
        diff.push_back(abs(v[i] - v[i - 1]));
    }
    debug(diff);

    int m = diff.size();
    debug(m);

    SegmentTree<int> seg(diff);

    int l = 0, r = 0;
    for (int qq = 0; qq < q; qq++)
    {
        cin >> l >> r;
        l--;
        r--;

        int gcd = seg.query(l, r - 1);
        cout << gcd << ' ';
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