#include <iostream>
#include <set>
using namespace std;

#define el << '\n'
#define ws << ' '

class SmallestInfiniteSet
{
    set<int> a;

public:
    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
            a.insert(i);
    }

    int popSmallest()
    {
        int temp = *a.begin();
        a.erase(a.begin());
        return temp;
    }

    void addBack(int num)
    {
        a.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
int main()
{

    return 0;
}