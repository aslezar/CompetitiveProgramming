#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

int totalFruit(vector<int> &fruits)
{
    if (fruits.size() < 3)
        return fruits.size();
    int finalans = 0;

    int secondNumber = fruits[0];
    int lastElement = fruits[1];
    int streakOflastelement = 1;
    if (secondNumber == lastElement)
    {
        secondNumber = -1;
        streakOflastelement = 2;
    }
    int ans = 2;
    for (int i = 2; i < fruits.size(); i++)
    {
        cout << i ws << fruits[i] ws << lastElement ws << streakOflastelement ws << secondNumber ws << ans ws << finalans el;
        if (fruits[i] == lastElement)
        {
            streakOflastelement++;
            ans++;
        }
        else if (fruits[i] == secondNumber)
        {
            streakOflastelement = 1;
            secondNumber = lastElement;
            lastElement = fruits[i];
            ans++;
        }
        else
        {
            if (secondNumber == -1)
            {
                ans++;
                secondNumber = lastElement;
                lastElement = fruits[i];
                streakOflastelement = 1;
            }
            else
            {
                if (finalans < ans)
                    finalans = ans;
                ans = streakOflastelement + 1;
                secondNumber = lastElement;
                lastElement = fruits[i];
                streakOflastelement = 1;
            }
        }
    }
    if (finalans < ans)
        finalans = ans;
    return finalans;
}

int main()
{
    vector<int> a = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << totalFruit(a);
    return 0;
}