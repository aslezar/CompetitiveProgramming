#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

struct st
{
    int x;
     int y;
};
int main()
{
    cout << sizeof(struct st);
    cout << '\n';
    cout << sizeof(int);
    return 0;
}