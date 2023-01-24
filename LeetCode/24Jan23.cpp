#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

int abc(vector<int> &board, int pos, int no)
{
    cout el << "Hello" ws << board.size() ws << pos ws << no el;
    if (pos == board.size() - 1)
        return no;
    if (pos + 7 >= board.size())
        return no + 1;
    int temp=0;
    for (int i = pos + 1; i < pos + 7; i++)
    {
        if (board[i] != -1)
        {
            temp = abc(board, board[i] - 1, no);
        }
    }
    // if (pos + 6 == board.size() - 1)
    //     return min(+no, no + 1);
    // no = min(no, abc(board, pos + 6, no));
    return no+temp;
}
int snakesAndLadders(vector<vector<int>> &board)
{
    vector<int> no;
    int size = board.size();
    for (int row = size - 1; row >= 0; row--)
    {
        if ((size + row) % 2 == 0)
            // straigh row
            for (int column = size - 1; column >= 0; column--)
                no.push_back(board[row][column]);
        else
            // reverse row
            for (int column = 0; column < board.size(); column++)
                no.push_back(board[row][column]);
    }
    size *= size;
    for (int i = 0; i < size; i++)
        cout << no[i] ws;
    int a = abc(no, 0, 0);
    return a;
}

int main()
{
    vector<vector<int>> board =
        {{-1, -1, -1, -1, -1, -1},
         {-1, -1, -1, -1, -1, -1},
         {-1, -1, -1, -1, -1, -1},
         {-1, 35, -1, -1, 13, -1},
         {-1, -1, -1, -1, -1, -1},
         {-1, 15, -1, -1, -1, -1}};
    cout << snakesAndLadders(board) el;

    return 0;
}