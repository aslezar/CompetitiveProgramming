#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int a = 0;
    while (1)
    {
        cin >> a;
        if (a == 42)
            break;
        cout << a << '\n';
    }
    return 0;
}
