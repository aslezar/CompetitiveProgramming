#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int n = 0, k = 0;
    cin >> n >> k;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;
        if (temp == k)
        {
            flag = true;
            break;
        }
    }
    cout << (flag ? 1 : -1);
    return 0;
}
