#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int32_t main(int argc, char *argv[])
{
    srand(atoi(argv[1]));
    cout << "1\n";
    int n = rand(3, 10);
    cout << n << '\n';
    // set<int> used;
    for (int i = 0; i < n; i++)
    {
        int x;
        // do {
        x = rand(1, 2 * n);
        // } while (used.count(x));
        cout << x << ' ';
        // used.insert(x);
    }
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        int x;
        // do {
        x = rand(1, 2 * n);
        // } while (used.count(x));
        cout << x << ' ';
        // used.insert(x);
    }
    cout << '\n';
    return 0;
}