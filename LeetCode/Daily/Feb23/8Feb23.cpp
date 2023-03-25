#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define el << '\n'
#define ws << ' '
int jump(vector<int> &nums)
{
    int size = nums.size();

    vector<int> visited(nums.size(), -1);
    visited[0] = 0;

    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int curcell = q.front();
        for (int i = min(curcell + nums[curcell], size - 1); i < curcell + 1; i--)
        {
            if (i + 1 == size)
                return visited[curcell] + 1;
            if (visited[i] == -1) // means not-visited
            {
                visited[i] = visited[curcell] + 1;
                q.push(i);
            }
        }
        q.pop();
    }
    return visited[size - 1];
}
// Other backward approac
// class Solution
// {
// public:
//     int jump(vector<int> &nums)
//     {
//         int size = nums.size();
//         if (size == 1)
//             return 0;

//         vector<int> visited(nums.size(), -1);
//         visited[0] = 0;

//         queue<int> q;
//         q.push(0);

//         while (!q.empty())
//         {
//             int curcell = q.front();
//             for (int i = curcell + nums[curcell]; i > curcell; i--)
//             {
//                 if (i >= size - 1)
//                     return visited[curcell] + 1;
//                 if (visited[i] == -1) // means not-visited
//                 {
//                     visited[i] = visited[curcell] + 1;
//                     q.push(i);
//                 }
//             }
//             q.pop();
//         }
//         return visited[size - 1];
//     }
// };
int main()
{
    return 0;
}