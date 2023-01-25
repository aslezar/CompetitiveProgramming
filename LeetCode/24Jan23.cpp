#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define el << '\n'
#define ws << ' '

// int abc(vector<int> &board, int pos, int no, int ans)
// {
//     cout << board.size() ws << pos ws << no ws << ans el;
//     if (pos == board.size() - 1)
//         return no;
//     if (pos + 7 >= board.size())
//         return no + 1;
//     for (int i = pos + 1; i < pos + 7; i++)
//     {
//         if (board[i] - 1 == i || board[i] == 1)
//             board[i] = -2;
//         if (board[i] != -1 && board[i] != -2 && board[board[i] - 1] != -2)
//         {
//             int temp = board[i];
//             board[i] = -2; // means already checked
//             ans = min(ans, abc(board, temp - 1, no + 1, ans));
//             // board[i] = temp;
//         }
//         else
//             board[i] = -2;
//     }

//     if (board[pos + 6] == -1 && board[pos + 6] != -2)
//     {
//         int temp = board[pos + 6];
//         board[pos + 6] = -1;
//         ans = min(ans, abc(board, pos + 6, no + 1, ans));
//         board[pos + 6] = temp;
//     }
//     return ans == INT_MAX ? -1 : ans;
// }
int snakesAndLadders(vector<vector<int>> &customBoard)
{
    vector<int> board;
    int size = customBoard.size();
    for (int row = size - 1; row >= 0; row--)
    {
        if ((size + row) % 2 == 0)
            // straigh row
            for (int column = size - 1; column >= 0; column--)
                board.push_back(customBoard[row][column]);
        else
            // reverse row
            for (int column = 0; column < customBoard.size(); column++)
                board.push_back(customBoard[row][column]);
    }
    size *= size;
    // for (int i = 0; i < size; i++)
    //     cout << board[i] ws;
    // cout el;

    vector<int> visited(size, -1);
    visited[0] = 0;

    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int curcell = q.front();
        for (int i = curcell + 1; i < min(curcell + 7, size); i++)
        {
            int dest = (board[i] != -1 ? board[i]-1 : i);
            if (visited[dest] == -1) // means not-visited
            {
                visited[dest] = visited[curcell] + 1;
                q.push(dest);
            }
        }
        q.pop();
    }
    // int a = abc(no, 0, 0, INT_MAX);
    // cout << "OKAY";
    return visited[size - 1];
}

int main()
{
    // 4
    vector<vector<int>> board =
        {{-1, -1, -1, -1, -1, -1},
         {-1, -1, -1, -1, -1, -1},
         {-1, -1, -1, -1, -1, -1},
         {-1, 35, -1, -1, 13, -1},
         {-1, -1, -1, -1, -1, -1},
         {-1, 15, -1, -1, -1, -1}};
    // 1
    //  vector<vector<int>> board =
    //      {{-1, -1, -1},
    //       {-1, 9, 8},
    //       {-1, 8, 9}};
    //       //1
    //  vector<vector<int>> board =
    //      {{-1, 7, -1},
    //       {-1, 6, 9},
    //       {-1, -1, 2}};
    // vector<vector<int>> board = {{-1, -1, 2, -1},
    //                              {2, 13, 15, -1},
    //                              {-1, 10, -1, -1},
    //                              {-1, 6, 2, 8}};

    cout << snakesAndLadders(board) el;
    return 0;
}