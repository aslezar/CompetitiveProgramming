#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t = 0;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << a * 1.1 - (a - b) << '\n';
    }
    return 0;
}
