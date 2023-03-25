#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int size = arr.size();
        if (size == 1)
            return 0;

        queue<int> q;
        vector<int> visited(size, -1);

        q.push(0);
        visited[0] = 0;

        while (!q.empty())
        {
            int qsize = q.size();
            while (qsize--)
            {
                int cur = q.front();
                q.pop();
                if (cur == size - 1)
                    return visited[cur];
                for (int i = 0; i < size; i++)
                {
                    if (arr[i] == arr[cur] && i != cur)
                    {
                        if (visited[i] == -1)
                        {
                            q.push(i);
                            visited[i] = visited[cur] + 1;
                        }
                    }
                }
                if (cur - 1 >= 0 && visited[cur - 1] == -1)
                {
                    q.push(cur - 1);
                    visited[cur - 1] = visited[cur] + 1;
                }
                if (cur + 1 < size && visited[cur + 1] == -1)
                {
                    q.push(cur + 1);
                    visited[cur + 1] = visited[cur] + 1;
                }
            }
        }
        return -1;
    }
};
int main()
{
    // vector<int> a = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    vector<int> a = {6, 1, 9};
    Solution s;
    cout << s.minJumps(a) el;

    return 0;
}