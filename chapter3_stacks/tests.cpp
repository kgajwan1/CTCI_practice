#include<bits/stdc++.h>

class Stack{
    int top;
    public:
    Stack() {top= -1;}
    int a[100];
    bool push (int x);
    int peek();
    int pop();
    bool isEmpty();
    int size_stack();
};

bool Stack::push(int x)
{
        if(top > 99)
            {
                std::cout<<" Stack Overflow"<<'\n';
                return false;
            }
        else 
            {
                a[++top]  = x;
                std::cout << x << " pushed in stack\n";
                return true;
            }

}
bool Stack::isEmpty()
{
    return (top<0);
}
int Stack::peek()
{
    if (top<0)
    {
        std::cout << "Stack is Empty"<<'\n';
        return 0;
    }
    return a[top];
}

int Stack::pop()
{
    if (top <0)
    {
        return 0;
    }
    else
    {
        int x = a[top];
        a[top--];
        return x;
    }
    
}
void showStack(Stack s)
{
    while (!s.isEmpty())
    {
        std::cout << s.pop()<<" showstack\n";
        
    }
}
int Stack::size_stack()
{
    int count = 1;
    int b = top;
    while (b -- )
    {
        count ++;      
    }

    return count;
}

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(03);
    std::cout <<s.size_stack()<< " stack size\n";
    std::cout <<s.pop()<< " taken out from top of stack\n";
    std::cout<< s.peek()<< " peek operation\n"; //this is std::stacks top equivalent 
    
    showStack(s);   
  //  std::cout <<std::boolalpha<<s.isEmpty();
}