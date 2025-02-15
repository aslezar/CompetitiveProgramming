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

class Node
{

public:
    int key;
    int value;
    Node *next;
    Node *prev;
    Node(int k, int v) : key(k), value(v) {}
    int getValue() { return value; }
    void setValue(int v) { value = v; }
};  
class LRUCache
{
    int capacity;
    unordered_map<int, Node *> keyMap;
    Node *head, *tail;

public:
    LRUCache(int capacity) : capacity(capacity)
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void push_to_front(Node *cur)
    {
        Node *nxt = head->next;
        cur->next = nxt;
        cur->prev = head;
        head->next = cur;
        nxt->prev = cur;
    }

    void remove_node(Node *cur)
    {
        Node *prev = cur->prev;
        Node *nxt = cur->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    int get(int key)
    {
        if (keyMap.find(key) == keyMap.end())
        {
            return -1;
        }
        Node *cur = keyMap[key];
        int val = cur->getValue();
        remove_node(cur);
        push_to_front(cur);
        return val;
    }

    void put(int key, int value)
    {
        if (keyMap.find(key) == keyMap.end())
        {
            if (keyMap.size() == capacity)
            {
                Node *toDel = tail->prev;
                keyMap.erase(toDel->key);
                remove_node(toDel);
                delete toDel;
            }
            push_to_front(new Node(key, value));
            keyMap[key] = head->next;
            return;
        }
        // exists
        Node *cur = keyMap[key];
        cur->setValue(value);
        remove_node(cur);
        push_to_front(cur);
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