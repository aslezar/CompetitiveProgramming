#include <iostream>
#include <vector>
#include <math>
using namespace std;

#define el << '\n'
#define ws << ' '
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int i = num.size() - 1;
        while (k)
        {
            num[i] += (k % 10);
            k /= 10;
            if (num[i] > 9)
            {
                num[i] -= 10;
                k++;
            }
            i--;
            if (i < 0)
            {
                while (k)
                {
                    num.insert(num.begin(), k % 10);
                    k /= 10;
                }
                break;
            }
        }
        return num;
    }
};
int main()
{

    return 0;
}