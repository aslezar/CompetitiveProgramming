#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

int main()
{
    pair<int, string> p;
    p = make_pair(2, "abc");
    cout << p.first ws << p.second el;

    p = {2, "abc"};
    cout << p.first ws << p.second el;

    pair<int, string> p1;
    p1.first = 96;
    p1.second = "svv";
    cout << p1.first ws << p1.second el;
    
    return 0;
}