#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b > c && b + c > a && a + c > b)
    {
        if (a == b)
        {
            if (b == c)
                cout << 1;
            else
                cout << 2;
        }
        else
        {
            if (b == c)
                cout << 2;
            else
                cout << 3;
        }
    }
    else
        cout << -1;
    return 0;
}