#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t = 0;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b == c)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}