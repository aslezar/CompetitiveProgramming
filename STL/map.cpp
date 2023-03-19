#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

#define el << '\n'
#define ws << ' '

int main()
{
    // Maps uses red black tree for their implementaion
    map<int, string> m;
    m[1] = "abc"; // O(log(n))
    m.insert({5, "asdf"});
    m[2] = "cdc";
    for (auto &&i : m)
        cout << i.first ws << i.second el;
    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->first ws << it->second el;

    auto it = m.find(3); // O(log(n))
    if (it != m.end())
    {
        cout << it->first ws << it->second el;
        m.erase(it); // It will delete the value from the map. O(log n)
        // m.erase(3);
    }
    else
        cout << "NoValue\n";

    // m.clear(); //Delete whole map
    // m["abcd"] = "abcd"; // O(s.size() * log(N)) return 0;

    // Frequency Map
    // map<int, int> f;
    // int n = 0;
    // cin >> n;
    // int temp = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> temp;
    //     m[temp]++;
    // }

    // Unordered Maps
    //  1.Implementaion using Heap
    //  2.Time Complexity log(1)
    //  3.Valid Keys unordered_map<pair<int,int>,string> gives compiler error

    unordered_map<int, int> um;
    multimap<int, int> mm; // Duplicates value also can be stored
}