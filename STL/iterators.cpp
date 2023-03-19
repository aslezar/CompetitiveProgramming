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
    vector<int> v = {2, 3, 4, 5, 6};
    vector<int>::iterator it = v.begin();
    // auto it = v.begin();
    
    cout << (*(it + 1)) el; // this works for vector because vector are continous in memory
    for (; it != v.end(); ++it)
        cout << *it ws;
    cout el;
    // it+1 and it++ are differenet

    for (int value : v)
        cout << value ws;
    // value is not a refernces its a copy
    // to change value also use & for refernce
    cout el;

    vector<pair<int, int>> v_p = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    vector<pair<int, int>>::iterator it2 = v_p.begin();
    cout << it2->first el;
    cout << (*it2).second el;
    return 0;
}