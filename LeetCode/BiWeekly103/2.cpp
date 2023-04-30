#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int commonele(vector<int> &a, vector<int> &b, int size)
    {
        int ans = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (a[i] == b[j])
                    ans++;
            }
        }
        return ans;
    }
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        vector<int> ans(A.size(), 0);
        for (int i = 0; i < A.size(); i++)
        {
            ans[i] = commonele(A, B, i + 1);
        }
        return ans;
    }
};

int main()
{

    return 0;
}