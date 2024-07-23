#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {}
    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int x = s1.top();
        s1.pop();
        return x;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        if (s1.size() == 0 && s2.size() == 0)
            return true;
        return false;
    }
};

int main()
{
    MyQueue myQueue;
    myQueue.push(1);         // queue is: [1]
    myQueue.push(2);         // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue.peek();  // return 1
    cout << myQueue.pop();   // return 1, queue is [2]
    cout << myQueue.empty(); // return false
}