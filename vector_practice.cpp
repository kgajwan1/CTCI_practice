//implement vector in c++
//simple begin and end

#include<iostream>
#include<vector>

int main()
{
    std::vector<int> g1;
    
    for (int i = 0; i<5;i++)
    {
        g1.push_back(i);
    }
   
   //standard use
   //begin() – Returns an iterator pointing to the first element in the vector
   //end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
   
    std::cout << "Output of begin and end: "<<'\n'; 
    for (auto i = g1.begin(); i != g1.end(); ++i) 
        std::cout << *i << " "; 
    printf("\n");
    
    //reverse output
    //rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
    //rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end) 
   
   std::cout << "Output of rbegin and rend: "<<'\n'; 
    for (auto i = g1.rbegin(); i != g1.rend(); ++i) 
        std::cout << *i << " "; 
            printf("\n");

    
    //standard
    // cbegin() – Returns a constant iterator pointing to the first element in the vector.
    //cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector. 
   
   std::cout << "Output of cbegin and cend: "<<'\n'; 
    for (auto i = g1.cbegin(); i != g1.cend(); ++i) 
        std::cout << *i << " "; 
            printf("\n");
    
    //crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
    //crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
    
    std::cout << "Output of crbegin and crend: "<<'\n'; 
    for (auto i = g1.crbegin(); i != g1.crend(); ++i) 
        std::cout << *i << " "; 
            printf("\n");

}
