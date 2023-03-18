#include <iostream>
using namespace std;

#define el << '\n'
#define ws << ' '

class Node
{
    string url;

public:
    Node *prev;
    Node *next;
    Node(string a) : url(a), next(nullptr), prev(nullptr) {}
    ~Node()
    {
        delete prev;
        delete next;
    }
    string returnURL()
    {
        return url;
    }
};
class BrowserHistory
{
    Node *curr;

public:
    BrowserHistory(string homepage)
    {
        curr = new Node(homepage);
    }

    void visit(string url)
    {
        if (curr == nullptr)
        {
            curr = new Node(url);
            return;
        }
        curr->next = new Node(url);
        Node *temp = curr;
        curr = curr->next;
        curr->prev = temp;
    }

    string back(int steps)
    {
        for (int i = 0; i < steps; i++)
        {
            if (curr->prev == nullptr)
                return curr->returnURL();
            curr = curr->prev;
        }
        return curr->returnURL();
    }

    string forward(int steps)
    {
        for (int i = 0; i < steps; i++)
        {
            if (curr->next == nullptr)
                return curr->returnURL();
            curr = curr->next;
        }
        return curr->returnURL();
    }
};
int main()
{

    return 0;
}