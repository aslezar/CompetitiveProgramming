#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

class ParkingSystem
{
public:
    int b, m, s;
    ParkingSystem(int big, int medium, int small)
    {
        b = big;
        m = medium;
        s = small;
    }

    bool addCar(int carType)
    {
        switch (carType)
        {
        case 1:
            if (b != 0)
            {
                b--;
                return true;
            }
            break;
        case 2:
            if (m != 0)
            {
                m--;
                return true;
            }
            break;
        case 3:
            if (s != 0)
            {
                s--;
                return true;
            }
            break;
        }
        return false;
    }
};
int main()
{

    return 0;
}