#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int n = 0;
    cin >> n;
    cout << ((n % 5 && n % 6) ? "NO" : "YES") << '\n';
    return 0;
}
