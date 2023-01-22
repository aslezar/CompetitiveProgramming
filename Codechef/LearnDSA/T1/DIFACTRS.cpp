#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

int main()
{
    // your code goes here
    int n = 0;
    cin >> n;
    vector<int> fac;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            fac.push_back(i);
    cout << fac.size() << ' ';
    for (int i = 0; i < fac.size(); i++)
        cout << fac[i] << ' ';
    return 0;
}
