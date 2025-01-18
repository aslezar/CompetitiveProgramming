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

vector<string> split(const string &str, char delimiter)
{
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

int timeToMins(string time)
{
    auto words = split(time.substr(0, time.length() - 2), ':');
    assert(words.size() == 2);
    int hrs = stoi(words[0]);
    int mins = stoi(words[1]);
    if (time.substr(time.length() - 2) == "PM" && hrs != 12)
    {
        hrs += 12;
    }
    else if (time.substr(time.length() - 2) == "AM" && hrs == 12)
    {
        hrs = 0;
    }
    return hrs * 60 + mins;
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    debug(n);

    string s;
    // vector<vector<string>> logs;
    unordered_map<string, vector<pair<int, pair<string, string>>>> logs;
    for (int i = 0; i < n; i++)
    {
        vector<string> words;
        for (int j = 0; j < 4; j++)
        {
            cin >> s;
            words.push_back(s);
        }
        debug(words);
        assert(words.size() == 4);
        logs[words[0]].push_back({timeToMins(words[3]), {words[2], words[1]}});
    }
    string doubtId;
    cin >> doubtId;
    debug(logs);

    unordered_map<string, int> timeinRoom;

    for (auto &em : logs)
    {
        string id = em.first;
        if (em.second.size() % 2 != 0)
        {
            debug(id, em.second.size());
            cout << "Cannot be determined\n";
            return;
        }
        sort(em.second.begin(), em.second.end());
        auto eLog = em.second;
        for (int i = 0; i < (int)eLog.size(); i += 2)
        {
            if (eLog[i].second.first != eLog[i + 1].second.first)
            {
                debug(em.second);
                debug(id, i);
                // Tailgating
                cout << "Cannot be determined\n";
                return;
            }
            if (eLog[i].second.second != "enters" || eLog[i + 1].second.second != "exits")
            {
                debug(em.second);
                debug(id, i);

                // Tailgating
                cout << "Cannot be determined\n";
                return;
            }
            if (eLog[i].second.first.compare(0, 4, "room") == 0)
                timeinRoom[id] += (eLog[i + 1].first - eLog[i].first);
        }
    }

    if (!timeinRoom.count(doubtId))
    {
        cout << "Yes\n";
        return;
    }

    for (auto &i : timeinRoom)
    {
        if (i.second < timeinRoom[doubtId])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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