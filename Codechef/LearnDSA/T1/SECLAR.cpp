#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int input(int a = 0)
{
    cin >> a;
    return a;
}
int main()
{
    //Approach 1:
    set<int> a;
    a.insert(input());
    a.insert(input());
    a.insert(input());
    auto t = a.begin();
    cout << *(++t) << '\n';

    //Approach 2:
    // int a, b, c;
    // cin >> a >> b >> c;
    // if (a > b)
    //     swap(a, b);

    // if (a > c)
    //     cout << a;
    // else
    // {
    //     if (b > c)
    //         cout << c;
    //     else
    //         cout << b;
    // }
    return 0;
}
