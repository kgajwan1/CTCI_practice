//sort a stack using temporary stack

#include<bits/stdc++.h>

std::stack<int> SortStack(std::stack<int> &input)
{
     std::stack<int> tmpstack;

     while (!input.empty())
     {
         /* code */
         int tmp = input.top(); 
        input.pop(); 

        while(!tmpstack.empty() && tmpstack.top()< tmp)
        {
            input.push(tmpstack.top());
            tmpstack.pop();
        }
        tmpstack.push(tmp); 
     }
     return tmpstack; 
     
}

int main()
{
std::stack<int> input; 
    input.push(34); 
    input.push(3); 
    input.push(31); 
    input.push(98); 
    input.push(92); 
    input.push(23); 
  
    // This is the temporary stack 
    std::stack<int> tmpStack = SortStack(input); 
    std::cout << "Sorted numbers are:\n"; 
  
    while (!tmpStack.empty()) 
    { 
       std:: cout << tmpStack.top()<< " "; 
        tmpStack.pop(); 
    } 
}