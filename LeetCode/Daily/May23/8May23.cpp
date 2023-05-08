#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int sum = 0;
        int size = mat.size();
        for (int i = 0; i < size; i++)
        {
            sum += (mat[i][i] + mat[i][size - i - 1]);
        }
        if (size & 1)
        {
            size /= 2;
            sum -= mat[size][size];
        }
        return sum;
    }
};
int main()
{

    return 0;
}