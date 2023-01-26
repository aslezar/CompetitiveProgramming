#include <iostream>
using namespace std;
#define el << '\n'

int main()
{
    // your code goes here
    int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int t = 0;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int m = a * b * c;
        for (int i = 0; i < 25; i++)
        {
            if (m % p[i] != 0)
            {
                cout << p[i] el;
                break;
            }
        }
    }
    return 0;
}
