#ifdef LOCAL_RUN
#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

// #define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

struct Node
{
    int use;
    int key;
    int value;
    Node(int key, int value, int use = 1) : key(key), value(value), use(use) {}
};

class LFUCache
{
    int capacity;
    int minFreq;
    unordered_map<int, list<Node>::iterator> keyMap;
    unordered_map<int, list<Node>> data;

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0)
    {
    }

    int get(int key)
    {
        if (keyMap.find(key) == keyMap.end())
        {
            return -1;
        }
        // exists
        Node node = *keyMap[key];
        data[node.use].erase(keyMap[key]);
        if (data[node.use].size() == 0 && minFreq == node.use)
        {
            minFreq++;
        }
        node.use++;
        data[node.use].push_front(node);
        keyMap[key] = data[node.use].begin();
        return node.value;
    }

    void put(int key, int value)
    {
        if (keyMap.find(key) != keyMap.end())
        {
            Node node = *keyMap[key];
            data[node.use].erase(keyMap[key]);
            if (data[node.use].size() == 0)
            {
                data.erase(node.use);
                if (minFreq == node.use)
                {
                    minFreq++;
                }
            }
            node.use++;
            node.value = value;
            data[node.use].push_front(node);
            keyMap[key] = data[node.use].begin();
        }
        else
        {
            if (keyMap.size() == capacity)
            {
                // delete
                keyMap.erase(data[minFreq].back().key);
                data[minFreq].pop_back();
            }
            // add
            Node node(key, value, 1);
            data[node.use].push_front(node);
            keyMap[key] = data[node.use].begin();
            minFreq = 1;
        }
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    cout << '\n';

    return 0;
}

#endif