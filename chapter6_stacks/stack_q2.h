#include<iostream>
#include<stdlib.h> 

class Stack{
    private:
    static const int max = 100; 
    int arr[max]; 
    int top; 

    public:
    Stack()  {top = -1;}
    bool push (int x);   
    int pop();
    int peek();
    bool isFull();
    bool isEmpty();
};

bool Stack::push(int n)
{
    if (isFull())
    {
        std::cout <<arr [top] << " : top \n";
        std::cout << "stack overflow\n";
        abort();
    }
    else 
    {
        arr[++top] = n;
        return true;
    }
}

int Stack::pop()
{
    if(isEmpty())
    {
        std::cout <<"stack underflow\n";
        return 0;
    }
    return arr[top--];
}

int Stack::peek()
{
    if(top < 0)
    {
        std::cout <<"stack is empty\n";
        return 0;
    }
    return arr[top];
}

bool Stack::isEmpty()
{
    return (top<0);    
}
bool Stack::isFull()
{
    return (top >= (max-1));    
}
