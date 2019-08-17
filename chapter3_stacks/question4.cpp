#include<bits/stdc++.h>
#include"stack_q2.h"
//i can use std::Stack here, so not using my implementation,
// mine should work. ill be testing after solving
class Queue{
    public:
    std::stack<int> s1,s2;
    
    void enQueue(int x)
    {
        s1.push(x);
    } 
    int deQueue()
    {
        if(s1.empty() && s2.empty())
        {
            std::cout <<"empty queue\n";
            exit(0);
        }

        if(s2.empty())
        {
            while (!s1.empty())
            {
                /* code */
                s2.push(s1.top());
                s1.pop();
            }
            
        }
        int x = s2.top(); 
        s2.pop(); 
        return x; 
    }
};

class Queue_myStack{
    public:
    Stack s1,s2;
    void enQueue(int x)
    {
        s1.push(x);
    } 
    int deQueue()
    {
        if(s1.isEmpty() && s2.isEmpty())
        {
            std::cout <<"empty queue\n";
            exit(0);
        }

        if(s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                /* code */
                s2.push(s1.peek());
                s1.pop();
            }
            
        }
        //peek is my top equivalent
        //int x = s2.peek(); then s2.pop(); is fine too
        int x = s2.pop(); 
       // s2.pop(); 
        return x; 
    }
};
int main()
{
    Queue q; 
    Queue_myStack qt;
    q.enQueue(11); 
    q.enQueue(12); 
    q.enQueue(13); 
    q.enQueue(99); 
    q.enQueue(69); 
    qt.enQueue(11); 
    qt.enQueue(12); 
    qt.enQueue(13); 
    qt.enQueue(99); 
    qt.enQueue(69); 
    std::cout << q.deQueue() << '\n'; 
    std::cout << q.deQueue() << '\n'; 
    std::cout << q.deQueue() << '\n'; 
    std::cout << qt.deQueue() << '\n'; 
    std::cout << qt.deQueue() << '\n'; 
    std::cout << qt.deQueue() << '\n'; 
    return 0;
}