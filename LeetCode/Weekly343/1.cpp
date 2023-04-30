#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int isWinner(vector<int> &player1, vector<int> &player2)
    {
        int size = player1.size();
        int s1 = 0, s2 = 0;
        int d1 = 0, d2 = 0;
        for (int i = 0; i < size; i++)
        {
            s1 += player1[i];
            if (d1 != 0)
            {
                s1 += player1[i];
                d1--;
            }
            if (player1[i] == 10)
            {
                d1 = 2;
            }

            s2 += player2[i];
            if (d2 != 0)
            {
                s2 += player2[i];
                d2--;
            }
            if (player2[i] == 10)
            {
                d2 = 2;
            }
        }
        cout << s1 << ' ' << s2 << '\n';
        if (s1 == s2)
            return 0;
        if (s1 > s2)
            return 1;
        return 2;
    }
};
int main()
{

    return 0;
}