//ctci examples to implement stack and queue
//implement a stack using array
#include<bits/stdc++.h>

class Stack{
    int top;
    public:

    int a[100];//size of stack, it can not be dynamic
    Stack()  {top = -1;}
    bool push (int x);
    
    int pop();
    int peek();
    bool isEmpty();
};
//make int push
//boolean is 0 or 1, might as well keep it

bool Stack::push(int x)
{
    if (top >= (99))
    {
        std::cout <<" Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
       
        return true;
    }
}
int Stack::pop()
{
    if (top < 0)
    {
        std::cout <<" stack Underflow";
        return 0;
    }
    else 
    {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top <0)
    {
        std::cout <<" stack is Empty";
        return 0;
    }
    else {
        return a[top];
    }

}
bool Stack::isEmpty()
{
    return (top<0);
}

void showStack(Stack s)
{
    while (!s.isEmpty())
    {
        std::cout << s.pop()<<" taken out from stack\n";
    }
}
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(03);
    std::cout <<s.pop()<< " from top of stack\n";
    std::cout<< s.peek()<< " peek operation\n"; //this is std::stacks top equivalent 
    showStack(s);   
}