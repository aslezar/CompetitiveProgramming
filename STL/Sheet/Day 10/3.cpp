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
    bool isValid(vector<vector<char>> &board, int row, int col, char value)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == value || board[i][col] == value)
            {
                return false;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[(row / 3) * 3 + i][(col / 3) * 3 + j] == value)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool solveSudokuHelper(vector<vector<char>> &board, int index)
    {

        if (index >= 9 * 9)
        {
            return true;
        }

        int r = index / 9;
        int c = index % 9;

        if (board[r][c] != '.')
        {
            return solveSudokuHelper(board, index + 1);
        }

        for (char i = '1'; i <= '9'; i++)
        {
            if (isValid(board, r, c, i))
            {
                board[r][c] = i;
                if (solveSudokuHelper(board, index + 1))
                    return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solveSudokuHelper(board, 0);
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