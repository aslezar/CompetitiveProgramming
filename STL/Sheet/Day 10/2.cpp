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
    bool validSequence(vector<string> &board, int row, int col)
    {
        int n = board.size();
        auto inBound = [&n](int r, int c) -> bool
        {
            return r >= 0 && r < n && c >= 0 && c < n;
        };

        // check same row
        for (int k = 0; k < col; k++)
        {
            if (board[row][k] == 'Q')
            {
                return false;
            }
        }

        // check same col
        for (int k = 0; k < row; k++)
        {
            if (board[k][col] == 'Q')
            {
                return false;
            }
        }

        // cur cell to top left
        int r = row - 1, c = col - 1;
        while (inBound(r, c))
        {
            if (board[r][c] == 'Q')
            {
                return false;
            }
            r--;
            c--;
        }

        // cur cell to upper right
        r = row - 1, c = col + 1;
        while (inBound(r, c))
        {
            if (board[r][c] == 'Q')
            {
                return false;
            }
            r--;
            c++;
        }

        return true;
    }
    void solveNQueensHelper(int n, int row, vector<string> &board,
                            vector<vector<string>> &ans)
    {

        if (row >= n)
        {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {

            board[row][col] = 'Q';

            if (validSequence(board, row, col))
            {
                solveNQueensHelper(n, row + 1, board, ans);
            }

            board[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solveNQueensHelper(n, 0, board, ans);
        return ans;
    }
};

class Solution2
{
    bool validSequence(vector<string> &board)
    {
        int n = board.size();
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (board[row][col] == 'Q')
                {

                    for (int k = 0; k < n; k++)
                    {
                        if (k != col && board[row][k] == 'Q')
                        {
                            return false;
                        }
                        if (k != row && board[k][col] == 'Q')
                        {
                            return false;
                        }
                    }

                    auto inBound = [&n](int r, int c) -> bool
                    {
                        return r >= 0 && r < n && c >= 0 && c < n;
                    };

                    // cur cell to top left
                    int r = row - 1, c = col - 1;
                    while (inBound(r, c))
                    {
                        if (board[r][c] == 'Q')
                        {
                            return false;
                        }
                        r--;
                        c--;
                    }

                    // cur cell to bottom right
                    r = row + 1, c = col + 1;
                    while (inBound(r, c))
                    {
                        if (board[r][c] == 'Q')
                        {
                            return false;
                        }
                        r++;
                        c++;
                    }
                    // cur cell to upper right
                    r = row - 1, c = col + 1;
                    while (inBound(r, c))
                    {
                        if (board[r][c] == 'Q')
                        {
                            return false;
                        }
                        r--;
                        c++;
                    }

                    // cur cell to bottom left
                    r = row + 1, c = col - 1;
                    while (inBound(r, c))
                    {
                        if (board[r][c] == 'Q')
                        {
                            return false;
                        }
                        r++;
                        c--;
                    }
                }
            }
        }
        return true;
    }
    void solveNQueensHelper(int n, int row, vector<string> &board,
                            vector<vector<string>> &ans)
    {

        if (row >= n)
        {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {

            board[row][col] = 'Q';

            if (validSequence(board))
            {
                solveNQueensHelper(n, row + 1, board, ans);
            }

            board[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solveNQueensHelper(n, 0, board, ans);
        return ans;
    }
};

#undef int
#ifdef LOCAL_RUN

int main()
{
    Solution s;
    s.solveNQueens(4);

    cout << '\n';

    return 0;
}

#endif