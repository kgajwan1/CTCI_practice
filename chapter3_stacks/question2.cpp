#include<bits/stdc++.h>
#include "stack_q2.h"

class SpecialStack : public Stack{
    Stack min;
    public:

    int pop();
    void push(int x);
    int getMin(); 
};

void SpecialStack::push(int x)
{
    if (isEmpty())
    {
        Stack::push(x); 
        min.push(x); 
    }
    else 
    {
        Stack::push(x);
        int y = min.pop();
        min.push(y);
        if(x<y){
            min.push(x);
        }
        else {
            min.push(y);
        }

    }
}

int SpecialStack::pop()
{
    int x = Stack::pop();
    min.pop();
    return x;
}
int SpecialStack::getMin() 
{ 
    int x = min.pop(); 
    min.push(x); 
    return x; 
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
    SpecialStack s; 
    s.push(10);
    s.push(20);

    s.push(03);
    s.push(4);
    
    std::cout << std::boolalpha<<s.isFull()<<'\n';
    std::cout<< s.getMin()<< " min operation\n"; //this is std::stacks top equivalent 
   // showStack(s);
}