#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

#define el << '\n'
#define ws << ' '

int main()
{
    set<int> a;
    int l = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                a.insert(pow(2, i) + pow(2, j) + pow(2, k));
                // a.insert(pow(2, i) + pow(2, j) + pow(2, k));
            }
        }
    }
    for (auto &&i : a)
    {
        cout << i ws;
    }

    // sort(a, a + 1000);
    // for (int i = 0; i < 1000; i++)
    // {
    //     if (a[i] % 2 == 0)
    //         cout << a[i] ws;
    // }

    return 0;
}