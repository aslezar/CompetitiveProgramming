#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

int main()
{
    // your code goes here4
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
            for (int j = 5; j > 0; j--)
                cout << i * 5 + j ws;
        else
            for (int j = 1; j <= 5; j++)
                cout << i * 5 + j ws;
        cout << '\n';
    }
    return 0;
}
