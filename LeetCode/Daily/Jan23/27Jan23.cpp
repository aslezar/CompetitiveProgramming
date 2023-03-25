#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define el << '\n'
#define ws << ' '

vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
{
    unordered_set<string> dict_word(words.begin(), words.end());
    vector<string> answer;
    for (const string &word : words)
    {
        const int size = word.length();
        vector<bool> visited(size + 1);
        visited[0] = 1;
        for (int i = 1; i <= size; ++i)
        {
            for (int j = (i == size ? 1 : 0); !visited[i] && j < i; ++j)
            {
                visited[i] = (visited[j] && dict_word.count(word.substr(j, i - j)));
            }
        }
        if (visited[size] == true)
        {
            answer.push_back(word);
        }
    }
    return answer;
}

int main()
{
    vector<string> a = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    vector<string> ans = findAllConcatenatedWordsInADict(a);
    for (auto &&i : ans)
    {
        cout << i ws;
    }

    return 0;
}