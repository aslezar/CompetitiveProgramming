#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);

    // take input
    //  4 2 8 5 1 3 6
    //  8

    vector<int> a(1000000);
    int load = 0;

    int temp;
    int i = 0;
    while (1)
    {
        cin >> temp;
        a[i] = temp;
        i++;
        if (cin.get() == '\n')
            break;
    }
    cin >> load;

    vector<int> arr;
    for (int j = 0; j < i; j++)
    {
        if (a[j] != 0)
            arr.push_back(a[j]);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    int sptr = 0;
    int eptr = arr.size() - 1;
    int ans = 0;

    while (sptr <= eptr)
    {
        if (arr[sptr] + arr[eptr] <= load)
        {
            eptr--;
        }
        sptr++;
        ans++;
    }
    cout << ans;
    return 0;
}