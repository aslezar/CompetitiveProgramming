#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 4;
const double INIT_PROBABILITY = 0.9;

class Board
{
private:
    int board[BOARD_SIZE][BOARD_SIZE];
    bool gameOver;
    bool gameWon;
    int score;
    int emptySpaces;

public:
    Board()
    {
        // Initialize the board with zeros
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                board[i][j] = 0;
            }
        }
        gameOver = false;
        gameWon = false;
        score = 0;
        emptySpaces = BOARD_SIZE * BOARD_SIZE;
        spawnTile();
        spawnTile();
    }

    // Spawn a new tile on a random empty space on the board
    void spawnTile()
    {
        if (emptySpaces == 0)
        {
            return;
        }
        int index = rand() % emptySpaces;
        int value = (rand() / double(RAND_MAX) < INIT_PROBABILITY) ? 2 : 4;
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (board[i][j] == 0)
                {
                    if (index == 0)
                    {
                        board[i][j] = value;
                        emptySpaces--;
                        return;
                    }
                    index--;
                }
            }
        }
    }

    // Move the tiles in a given direction
    void moveTiles(int direction)
    {
        int dx = 0;
        int dy = 0;
        switch (direction)
        {
        case 0: // Up
            dx = -1;
            break;
        case 1: // Right
            dy = 1;
            break;
        case 2: // Down
            dx = 1;
            break;
        case 3: // Left
            dy = -1;
            break;
        }
        bool hasMoved = false;
        for (int i = (dx == 1 ? BOARD_SIZE - 1 : 0); dx == 1 ? i >= 0 : i < BOARD_SIZE; i += dx)
        {
            for (int j = (dy == 1 ? BOARD_SIZE - 1 : 0); dy == 1 ? j >= 0 : j < BOARD_SIZE; j += dy)
            {
                if (board[i][j] == 0)
                {
                    continue;
                }
                int k = i + dx;
                int l = j + dy;
                while (k >= 0 && k < BOARD_SIZE && l >= 0 && l < BOARD_SIZE && board[k][l] == 0)
                {
                    k += dx;
                    l += dy;
                }
                if (k >= 0 && k < BOARD_SIZE && l >= 0 && l < BOARD_SIZE && board[k][l] == board[i][j])
                {
                    board[k][l] *= 2;
                    score += board[k][l];
                    board[i][j] = 0;
                    emptySpaces++;
                    hasMoved = true;
                }
                else
                {
                    k -= dx;
                    l -= dy;
                    if (k != i || l != j)
                    {
                        board[k][l] = board[i][j];
                        board[i][j] = 0;
                        hasMoved = true;
                    }
                }
            }
        }
        if (hasMoved)
        {
            spawnTile();
        }
    }
