#ifdef LOCAL_RUN
#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

// #define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int top = 0, down = n - 1;
        while (top < down)
        {
            if (mat[top][down] == 1)
            {
                // top knows down, he can not be celebrity
                top++;
            }
            else if (mat[down][top] == 1)
            {
                // down knows down, he can not be celebrity
                down--;
            }
            else
            {
                // both do not know each other, they can not be celebrities
                top++;
                down--;
            }
        }
        if (top == down)
        {
            for (int i = 0; i < n; i++)
            {
                if (i == top)
                    continue;
                if (mat[top][i] == 1 || mat[i][top] == 0)
                {
                    return -1;
                }
            }
            return top;
        }
        return -1;
    }
};

class Solution3
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            bool canCelebrity = true;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] != 0)
                {
                    canCelebrity = false;
                    break;
                }
            }
            if (canCelebrity)
            {
                bool isCelebrity = true;
                for (int k = 0; k < n; k++)
                {
                    if (k != i && mat[k][i] == 0)
                    {
                        isCelebrity = false;
                        break;
                    }
                }
                if (isCelebrity)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};

class Solution2
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            bool isCelebrity = true;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] != 0 || (j != i && mat[j][i] == 0))
                {
                    isCelebrity = false;
                    break;
                }
            }
            if (isCelebrity)
            {
                return i;
            }
        }
        return -1;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    cout << '\n';

    return 0;
}

#endif