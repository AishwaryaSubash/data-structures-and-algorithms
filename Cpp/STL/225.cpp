#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}
    void push(int x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        if (q1.size() == 0 && q2.size() == 0)
            return true;
        return false;
    }
};

int main()
{
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout << myStack.top();   // return 2
    cout << myStack.pop();   // return 2
    cout << myStack.empty(); // return False
}