//some vector practice

#include <iostream> 
#include <vector> 
#include<algorithm>
#include <bits/stdc++.h> 

int main() 
{ 
    std::vector<int> g1; 
  
    for (int i = 4; i >= 1; i--) 
        g1.push_back(i); 
    //earlier contents
    std::cout <<"Contents"<<std::endl;
   for (auto i = g1.begin(); i != g1.end(); i++)
    std::cout << *i <<" " ;
    printf("\n");
    

    //Size
   std::cout <<"Size vector G1"<<'\t'<< g1.size() << std::endl;
   //capacity
   std::cout << "capacity of G1"<<'\t' << g1.capacity() << std::endl;
   //maximum size 
   std::cout << "Max size of g1" <<'\t'<<  g1.max_size() << std::endl;
   //resize vector
   g1.resize(4);
   std::cout <<"Size vector G1 now"<<'\t'<< g1.size() << std::endl;
   
   //current content
   std::cout <<"Contents"<<std::endl;
   for (auto i = g1.begin(); i != g1.end(); i++)
    std::cout << *i <<" " ;
    printf("\n");
    
    g1.shrink_to_fit(); 
    sort(g1.begin(), g1.end());
    
    std::cout << "\nVector elements are: "; 
    for (auto it = g1.begin(); it != g1.end(); it++) 
       std::cout << *it << " "; 
    
    return 0; 
    
} 
