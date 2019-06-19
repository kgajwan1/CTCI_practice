//some vector practice
//Element access:
#include <iostream> 
#include <vector> 
  

int main() 
{ 
   std::vector<int> v;
    for (int i = 1; i <= 10; i++) 
        v.push_back(i * 10); 
  //accessing values one by one
  //akin to array ;
  //second position
  std::cout << v[1] << std::endl;
  std::cout << v[2] << std::endl; 
  //first element
  std::cout <<"first element:  "<< v.front() << std::endl;
  //last element
  std::cout << "last element:  "<<v.back() << std::endl;
  
    
    // pointer to the first element 
    int* pos = v.data(); 
  
    std::cout << "\nThe first element is " << *pos; 
    return 0; 
} 
