#ifndef DEBUG_TEMPLATE_CPP
#define DEBUG_TEMPLATE_CPP
#include <bits/stdc++.h>
// #define cerr cout
namespace __DEBUG_UTIL__
{
    using namespace std;
    /* Primitive Datatypes Print */
    void print(const char *x) { cerr << x; }
    void print(bool x) { cerr << (x ? "T" : "F"); }
    void print(char x) { cerr << '\'' << x << '\''; }
    void print(signed short int x) { cerr << x; }
    void print(unsigned short int x) { cerr << x; }
    void print(signed int x) { cerr << x; }
    void print(unsigned int x) { cerr << x; }
    void print(signed long int x) { cerr << x; }
    void print(unsigned long int x) { cerr << x; }
    void print(signed long long int x) { cerr << x; }
    void print(unsigned long long int x) { cerr << x; }
    void print(float x) { cerr << x; }
    void print(double x) { cerr << x; }
    void print(long double x) { cerr << x; }
    void print(string x) { cerr << '\"' << x << '\"'; }
    template <size_t N>
    void print(bitset<N> x) { cerr << x; }
    void print(vector<bool> v)
    { /* Overloaded this because stl optimizes vector<bool> by using
          _Bit_reference instead of bool to conserve space. */
        int f = 0;
        cerr << '{';
        for (auto &&i : v)
            cerr << (f++ ? ", " : "") << (i ? "T" : "F");
        cerr << "}";
    }
    /* Templates Declarations to support nested datatypes */
    template <typename T>
    void print(T &&x);
    template <typename T>
    void print(vector<vector<T>> mat);
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M]);
    template <typename F, typename S>
    void print(pair<F, S> x);
    template <typename T, size_t N>
    struct Tuple;
    template <typename T>
    struct Tuple<T, 1>;
    template <typename... Args>
    void print(tuple<Args...> t);
    template <typename... T>
    void print(priority_queue<T...> pq);
    template <typename T>
    void print(stack<T> st);
    template <typename T>
    void print(queue<T> q);
    /* Template Datatypes Definitions */
    template <typename T>
    void print(T &&x)
    {
        /*  This works for every container that supports range-based loop
            i.e. vector, set, map, oset, omap, dequeue */
        int f = 0;
        cerr << "{ ";
        for (auto &&i : x)
            cerr << (f++ ? ", " : ""), print(i);
        cerr << " }";
    }
    template <typename T>
    void print(vector<vector<T>> mat)
    {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M])
    {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename F, typename S>
    void print(pair<F, S> x)
    {
        cerr << '(';
        print(x.first);
        cerr << " => ";
        print(x.second);
        cerr << ')';
    }
    template <typename T, size_t N>
    struct Tuple
    {
        static void printTuple(T t)
        {
            Tuple<T, N - 1>::printTuple(t);
            cerr << ", ", print(get<N - 1>(t));
        }
    };
    template <typename T>
    struct Tuple<T, 1>
    {
        static void printTuple(T t) { print(get<0>(t)); }
    };
    template <typename... Args>
    void print(tuple<Args...> t)
    {
        cerr << "(";
        Tuple<decltype(t), sizeof...(Args)>::printTuple(t);
        cerr << ")";
    }
    template <typename... T>
    void print(priority_queue<T...> pq)
    {
        int f = 0;
        cerr << '{';
        while (!pq.empty())
            cerr << (f++ ? ", " : ""), print(pq.top()), pq.pop();
        cerr << "}";
    }
    template <typename T>
    void print(stack<T> st)
    {
        int f = 0;
        cerr << '{';
        while (!st.empty())
            cerr << (f++ ? ", " : ""), print(st.top()), st.pop();
        cerr << "}";
    }
    template <typename T>
    void print(queue<T> q)
    {
        int f = 0;
        cerr << '{';
        while (!q.empty())
            cerr << (f++ ? ", " : ""), print(q.front()), q.pop();
        cerr << "}";
    }
    /* Printer functions */
    void printer(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail)
    {
        /* Using && to capture both lvalues and rvalues */
        int i = 0;
        for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
            if (names[i] == '(' or names[i] == '<' or names[i] == '{')
                bracket++;
            else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
                bracket--;
        cerr << '[';
        string name(names, i);
        name.erase(std::remove(name.begin(), name.end(), ' '), name.end());
        cerr << name << "] = ";
        // cerr.write(names, i) << "] = ";
        print(head);
        if (sizeof...(tail))
            cerr << " || ", printer(names + i + 1, tail...);
        else
            cerr << "\n";
    }
    /* PrinterArr */
    void printerArr(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printerArr(const char *names, T arr[], size_t N, V... tail)
    {
        size_t ind = 0;
        for (; names[ind] and names[ind] != ','; ind++)
            cerr << names[ind];
        for (ind++; names[ind] and names[ind] != ','; ind++)
            ;
        cerr << " = {";
        for (size_t i = 0; i < N; i++)
            cerr << (i ? "," : ""), print(arr[i]);
        cerr << "}";
        if (sizeof...(tail))
            cerr << " ||", printerArr(names + ind + 1, tail...);
        else
            cerr << "]\n";
    }
}

#define debug(...) std::cerr << __LINE__ << ": ", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
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

//     bool b = true;
//     debug(b);

//     long long int l = 1000000000000000000;
//     debug(l);

//     pair<int, char> p = {1, 'a'};
//     debug(p);

//     tuple<int, char, bool> t = {1, 'a', true};
//     debug(t);

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

//     priority_queue<int> pq;
//     pq.push(1);
//     pq.push(2);
//     pq.push(3);
//     debug(pq);

//     bitset<5> bit(5);
//     bit[1] = 1;
//     bit[3] = 1;
//     debug(bit);

//     int arr[] = {1, 2, 3, 4, 5};
//     debug(arr);

//     bool barr[] = {1, 0, 1, 0, 1};
//     debug(barr);

//     vector<int> adj[5];
//     adj[0].push_back(1);
//     adj[0].push_back(2);
//     adj[1].push_back(3);
//     adj[2].push_back(4);
//     debug(adj);

//     int dp[5][5];
//     memset(dp, 0, sizeof(dp));
//     debug(dp);

//     vector<vector<bool>> vis(5, vector<bool>(5, 0));
//     debug(vis);

//     map<string, vector<pair<char, unordered_set<long long>>>> m;
//     m["hello"].push_back({'a', {1, 2, 3}});
//     m["world"].push_back({'b', {4, 5, 6}});
//     debug(m);

//     debug(a, c, b, l, p, t, v, s, st, q, pq, bit, arr, barr, m);
//     debug(a, c, b, l);

//     return 0;
// }
