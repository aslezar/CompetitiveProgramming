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

template <typename Func, typename... Args>
void measureTime(const std::string &label, Func func, Args &&...args)
{
    auto start = std::chrono::high_resolution_clock::now();
    func(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken by " << label << ": " << duration.count() << " seconds" << std::endl;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2>
using safe_map = unordered_map<T1, T2, custom_hash>;

const int size_prime = 1e7 + 1;
int spf[size_prime] = {0};
void SieveOfEratosthenes()
{
    spf[0] = spf[1] = 1;
    for (int i = 2; i < size_prime; i++)
    {
        if (spf[i] == 0) // means prime
        {
            spf[i] = i;
            for (int j = i * i; j < size_prime; j += i)
            {
                spf[j] = i;
            }
        }
    }
}

long long power_mod(long long base, long long exp, long long mod = 1e9 + 7)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

void solve([[maybe_unused]] ll &_case_no)
{
    int n = 0;
    cin >> n;

    int m = 0;
    cin >> m;

    vi v(n);
    input(v, n);

    int mx = *max_element(all(v));
    mx = max(mx, m);

    SieveOfEratosthenes();

    safe_map<int, int> fOfM;
    for (int i = 2; i <= m; i++)
    {
        int num = i;
        while (num != 1)
        {
            fOfM[spf[num]]++;
            num /= spf[num];
        }
    }
    debug(fOfM);

    int cnt = 1;
    for (auto &[prime, count] : fOfM)
    {
        cnt = (cnt * (count + 1)) % mod;
    }

    for (int i = 0; i < n; i++)
    {

        int num = v[i];
        safe_map<int, int> primes;
        while (num != 1)
        {
            primes[spf[num]]++;
            num /= spf[num];
        }

        int count = cnt;
        for (auto &[p, c] : primes)
        {
            count = (count * (fOfM[p] + 1 + c)) % mod;
            count = (count * power_mod(fOfM[p] + 1, mod - 2)) % mod;
        }
        cout << count << ' ';
    }
    cout el
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}