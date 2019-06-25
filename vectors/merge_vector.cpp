//merge vector
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>

void mergevector( std::vector<int> v1, std::vector<int> v2)
{
     std::vector<int> v3;
     for (int i = 0; i != v1.size(); ++i)
     {
            v3.push_back(v1[i]);
     } 
     
      for (int i = 0; i != v2.size(); ++i)
     {
            v3.push_back(v2[i]);
     } 

     for (auto i = v3.begin(); i != v3.end(); ++i)
     {
            std::cout<< *i<<", ";
     } 
 
}
int main()
{
 std::vector<int> v,v1;
 for (int i = 0 ;i<10;i++){
     v.push_back(i);
 }
 for (int i = 11 ;i<20;i++){
     v1.push_back(i);
  }
  mergevector(v,v1);
  
}
