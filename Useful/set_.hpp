#include <iostream>
#include "cp_functions.cpp"
#include <set>
using namespace std;

#define el << '\n'
#define ws << ' '

int main()
{

    set<int> a;
    a.insert(input());
    a.insert(input());
    a.insert(input());

    // To find element at particular index
    auto t = a.begin();
    cout << *(++t) << '\n';
    
    return 0;
}