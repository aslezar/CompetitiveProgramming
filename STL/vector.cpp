#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] ws;
    cout el;
}
int main()
{
    vector<int> v;
    int n;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        v.push_back(n);
    }
    print(v);
    cout << v.size() ws << v.max_size() ws << v.capacity() el;

    vector<int> v1(10);
    print(v1);
    v1.push_back(5);
    print(v1);

    vector<int> v2(10, 3);
    print(v2);
    v2.push_back(5);
    print(v2);

    vector<int> v3 = v; // O(n)
    print(v3);

    // Vector of Pair
    vector<pair<int, int>> v4;
    v4.push_back({1, 2});

    // Array of vector
    vector<int> v5[5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 2; j++)
        {
            cin >> n;
            v5[i].push_back(n);
        }
    for (int i = 0; i < 5; i++)
        print(v5[i]);

    return 0;
}