// 926. Flip String to Monotone Increasing
#include <iostream>
using namespace std;

#define el << '\n'
int minFlipsMonoIncr(string s)
{
    int flip = 0, count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            count++;
        else
        {
            flip = min(++flip, count);
        }
    }
    return flip;
}
int main()
{
    string a="010110";
    cout<<minFlipsMonoIncr(a);
    return 0;
}