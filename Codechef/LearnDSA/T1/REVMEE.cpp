#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int n = 0;
    cin >> n;
    int a[100000];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i > 0; i--)
        cout << a[i] << ' ';
    return 0;
}
