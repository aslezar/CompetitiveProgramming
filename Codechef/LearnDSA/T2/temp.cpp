#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

int main()
{
    int count =0;
    for (int i = 1; i < 61; i++)
    {
        cout<<i<<' '<<(i%5?count:++count)<<'\n';
    }
    
    return 0;
}