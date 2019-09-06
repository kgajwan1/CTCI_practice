#include <bits/stdc++.h>

//method 1
//use stl
void printAnagram(std::unordered_map<std::string, 
                              std::vector<std::string> >& store) 
{ 
    std::unordered_map<std::string, std::vector<std::string> >::iterator it; 
    for (it = store.begin(); it != store.end(); it++) { 
        std::vector<std::string> temp_vec(it->second); 
        int size = temp_vec.size(); 
        if (size > 1) { 
            for (int i = 0; i < size; i++) { 
                std::cout << temp_vec[i] << " "; 
            } 
            
        } 
    } 
} 

void storeinmap(std::vector <std::string> &s)
{
    std::unordered_map<std::string, std::vector<std::string>> storage;
    for (int i = 0;i< s.size();i++)
    {
        std::string tstring(s[i]);
        std::sort(tstring.begin(),tstring.end());
        if(storage.find(tstring)==storage.end())
        {
            std::vector<std::string> temp_vec; 
            temp_vec.push_back(s[i]); 
            storage.insert(make_pair(tstring, temp_vec)); 
        }
        else 
        {
            std::vector<std::string> temp_vec(storage[tstring]); 
            temp_vec.push_back(s[i]); 
            storage[tstring] = temp_vec; 
        }
    } 
        printAnagram(storage); 
} 

//method 2
//for tomorrow
int main() 
{ 
    // initialize vector of strings 
    std::vector<std::string> arr; 
    arr.push_back("geeksquiz"); 
    arr.push_back("geeksforgeeks"); 
    arr.push_back("abcd"); 
    arr.push_back("forgeeksgeeks"); 
    arr.push_back("zuiqkeegs"); 
    arr.push_back("cat"); 
    arr.push_back("act"); 
    arr.push_back("tca"); 
  
    // utility function for storing strings 
    // into hashmap 
    storeinmap(arr); 
    return 0; 
} 