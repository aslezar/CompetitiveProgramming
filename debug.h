#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE

template <typename A>
string to_string(A a);
string to_string(char s) { return "'" + string(1, s) + "'"; }
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "1" : "0"); }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename T>
string to_string(const std::vector<T> &vec)
{
    bool first = true;
    string result = "{";
    for (const auto &elem : vec)
    {
        if (!first)
            result += ", ";
        first = false;
        result += to_string(elem);
    }
    result += "}";
    return result;
}
template <typename T, typename Container, typename Compare>
string to_string(const std::priority_queue<T, Container, Compare> &pq)
{
    auto temp = pq;
    bool first = true;
    string result = "{";
    while (!temp.empty())
    {
        if (!first)
            result += ", ";
        first = false;
        result += to_string(temp.top());
        temp.pop();
    }
    result += "}";
    return result;
}
// for queue
template <typename T, typename Container>
string to_string(const std::queue<T, Container> &q)
{
    auto temp = q;
    bool first = true;
    string result = "{";
    while (!temp.empty())
    {
        if (!first)
            result += ", ";
        first = false;
        result += to_string(temp.front());
        temp.pop();
    }
    result += "}";
    return result;
}
// for stack
template <typename T, typename Container>
string to_string(const std::stack<T, Container> &s)
{
    auto temp = s;
    bool first = true;
    string result = "{";
    while (!temp.empty())
    {
        if (!first)
            result += ", ";
        first = false;
        result += to_string(temp.top());
        temp.pop();
    }
    result += "}";
    return result;
}
template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
            res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     // int, char, bool, long long int
//     // pair, tuple, vector, set, oset, map, omap, stack, queue, priority_queue, bitset
//     // int arr[], bool arr[], vector<int> adj[]
//     // int dp[100][200], vector<vector<bool>> vis(100, vector<bool> (200, 0))
//     // map<string, vector<pair<char, unordered_set<long long>>>> WHATTT;

//     int a = 10;
//     debug(a);

//     char c = 'a';
//     debug(c);

//     // bool b = true;
//     // debug(b);

//     long long int l = 1000000000000000000;
//     debug(l);

//     pair<int, char> p = {1, 'a'};
//     debug(p);

//     // tuple<int, char, bool> t = {1, 'a', true};
//     // debug(t);

//     vector<int> v = {1, 2, 3, 4, 5};
//     debug(v);

//     set<int> s = {1, 2, 3, 4, 5};
//     debug(s);

//     stack<int> st;
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     debug(st);

//     queue<int> q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     debug(q);

//     // priority_queue<int> pq;
//     // pq.push(1);
//     // pq.push(2);
//     // pq.push(3);
//     // debug(pq);

//     // bitset<5> bit(5);
//     // bit[1] = 1;
//     // bit[3] = 1;
//     // debug(bit);

//     // int arr[] = {1, 2, 3, 4, 5};
//     // debug(arr, 5);

//     // bool barr[] = {1, 0, 1, 0, 1};
//     // debug(barr, 5);

//     // vector<int> adj[5];
//     // adj[0].push_back(1);
//     // adj[0].push_back(2);
//     // adj[1].push_back(3);
//     // adj[2].push_back(4);
//     // debug(adj, 5);

//     // int dp[5][5];
//     // memset(dp, 0, sizeof(dp));
//     // debug(dp, 5, 5);

//     vector<vector<bool>> vis(5, vector<bool>(5, 0));
//     debug(vis);

//     map<string, vector<pair<char, unordered_set<long long>>>> m;
//     m["hello"].push_back({'a', {1, 2, 3}});
//     m["world"].push_back({'b', {4, 5, 6}});
//     debug(m);

//     return 0;
// }
