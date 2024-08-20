#include <iostream>
#include <vector>
using namespace std;

void printCurr(vector<vector<int>> &curr)
{
    for (auto &v : curr)
    {
        cout << "[ ";
        for (auto &i : v)
            cout << i << " ";
        cout << "]";
    }
    cout << endl;
}

void printAllSeq(vector<int> &v, int index, vector<vector<int>> &curr)
{
    if (index == v.size())
    {
        printCurr(curr);
        return;
    }
    // add to last sequence
    if (!curr.empty())
    {
        curr.back().push_back(v[index]);
        printAllSeq(v, index + 1, curr);
        curr.back().pop_back();
    }

    // add to new sequence
    curr.push_back({v[index]});
    printAllSeq(v, index + 1, curr);
    curr.pop_back();
}

int main()
{
    // [1 2 3 4 5]

    vector<int> v = {1, 2, 3, 4, 5};
    vector<vector<int>> curr;
    printAllSeq(v, 0, curr);

    return 0;
}
