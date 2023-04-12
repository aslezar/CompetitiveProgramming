#include <iostream>
#include <stack>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    string simplifyPath(string path)
    {
        if (path == "/")
            return path;
        stack<string> s;
        string ans;
        string word;
        for (size_t i = 0; i < path.size(); i++)
        {
            if (path[i] != '/')
            {
                word.push_back(path[i]);
            }
            else
            {
                if (word != "")
                {
                    if (word == "..")
                    {
                        if (!s.empty())
                            s.pop();
                    }
                    else if (word != ".")
                        s.push(word);
                    word = "";
                }
            }
        }
        if (word != "")
        {
            if (word == "..")
            {
                if (!s.empty())
                    s.pop();
            }
            else if (word != ".")
                s.push(word);
            word = "";
        }

        stack<string> sa;
        while (!s.empty())
        {
            sa.push(s.top());
            s.pop();
        }
        while (!sa.empty())
        {
            ans += "/";
            ans += sa.top();
            sa.pop();
        }
        return ans != "/" ? ans : "/";
    }
};

int main()
{
    Solution ans;
    cout << ans.simplifyPath("/home//path");
    return 0;
}