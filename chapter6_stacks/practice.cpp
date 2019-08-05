/*
empty() – Returns whether the stack is empty – Time Complexity : O(1)
size() – Returns the size of the stack – Time Complexity : O(1)
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
pop() – Deletes the top most element of the stack – Time Complexity : O(1)
 */

#include<bits/stdc++.h>

void showStack(std::stack<int> s)
{
    while (!s.empty())
    {
        std::cout << '\t'<<s.top();
        s.pop();
    }
}

int main()
{
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << "\ns.size() : " << s.size(); 
    std::cout << "\ns.top() : " << s.top();   
    std::cout << "\n s.pop() : "; 
    s.pop(); 
    showStack(s);
}
