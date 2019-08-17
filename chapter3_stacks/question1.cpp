//question 1
#include<bits/stdc++.h>
#include"stack_implementer.h"

int main()
{
    
    int k = 3;
    int n = 20;
    nStacks n_s(k,n);
    n_s.push(12,0);
    n_s.push(10,1);
    n_s.push(15,2);
    n_s.push(11,0);
    n_s.push(14,1);
    n_s.push(16,2);
    n_s.push(13,0);
    n_s.push(19,1);
    n_s.push(18,2);
    
    std::cout << "Popped element from stack 2 is " << n_s.pop(2) << std::endl; 
    std::cout << "Popped element from stack 1 is " << n_s.pop(1) << std::endl; 
    std::cout << "Popped element from stack 0 is " << n_s.pop(0) << std::endl; 


}