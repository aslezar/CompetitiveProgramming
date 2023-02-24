#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0, x = 0;
        cin >> n >> x;
        if (x == 0)
        {
            cout << '-';
            for (int i = 0; i < n - 1; i++)
                cout << '*';
        }
        if (x > n + 1 || x < ((n - 1) * -1))
        {
            cout << -1 << '\n';
            continue;
        }
        if (x < 0)
        {
            for (int i = 0; i < 1 - x; i++)
                cout << '-';
            for (int i = 0; i < n + x - 1; i++)
                cout << '*';
        }
        else if (x > 0)
        {
            for (int i = 0; i < x - 1; i++)
                cout << '+';
            for (int i = 0; i < n - x + 1; i++)
                cout << '*';
        }
        cout << '\n';
    }
    return 0;
}