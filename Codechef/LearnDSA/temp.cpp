#include <iostream>
#include <iomanip>
using namespace std;

#define el << '\n'
#define ws << ' '

int main(int argc, char const *argv[])
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int s = i + j;
            cout << i ws << j ws << setw(2) << s ws;
            int sum = (i + j) % 10;
            for (int k = 0; k < argv[1][0]; k++)
            {
                cout << setw(3) << (s % 3 ? "No" : "Yes") ws;
                // cout << sum ws;
                s += sum;
                sum = ((sum * 2) % 10);
            }
            cout el;
        }
    }
}