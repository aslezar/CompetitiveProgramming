#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define el << '\n'
#define ws << ' '

int main()
{
    set<int> s;
    s.insert(6);
    s.insert(5); // log(n)
    s.insert(7);
    for (auto &&i : s)
        cout << i ws;
    cout el;
    auto it = s.find(6);
    if (it != s.end())
        cout << "Element found: " << *it el;

    //Same difference for unorder set as for unorder map
    unordered_set<int> us;
    // Same difference for multi set as for multi map
    multiset<int> ms;
    return 0;
}