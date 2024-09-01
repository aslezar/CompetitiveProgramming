#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2)
    {
        return abs((coordinate1[0] - 'a' + coordinate1[1]) - (coordinate2[0] - 'a' + coordinate2[1])) % 2 == 0;
    }
};