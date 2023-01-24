#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

int main()
{
    int n = 1;
    for (int i = 0; i < 50; i++)
    {
        cout << (n ^ i) << ' ';
    }

    return 0;
}