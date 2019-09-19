#include<bits/stdc++.h>
/*
Permutations with Duplicates: Write a method to compute all permutations
of a string whose characters are not necessarily unique. 
The list of permutations should not have duplicates. 
*/
void printPerms(std::string, std::string = "");

bool shouldSwap(char *str, int start, int curr)
{
    for (int i = start;i< curr;i++)
        if (str[i] == str[curr])
                return 0;
    
    return 1;
}

//check method by krish munot
void printPerms(std::string remainder, std::string prefix)
{
  long length = remainder.length();
  
  if (!length) std::cout << prefix << std::endl;
  
  bool dup[128];
  
  memset(dup, false, sizeof(bool) * 128);
  
  for (int i = 0; i < length; ++i)
  {
    if (dup[remainder.at(i)]) continue;
    
    std::string str1 = i == 0 ? "" : remainder.substr(0,i);
    
    std::string str2 = i == length - 1 ? "" : remainder.substr(i+1,length);
    
    printPerms(str1 + str2, prefix + remainder.at(i));
  
    dup[remainder.at(i)] = true;
  }
}

void findPerm(char *str, int index, int n)
{
    int count = 0;
    if(index >= n)
    {
        count++;
        std::cout << str<< '\n';
        
        return;
    }

    for (int i = index; i<n; i++)
    {
        if(shouldSwap(str,index,i))
        {
            std::swap(str[index],str[i]);
            findPerm(str, index + 1, n); 
            std::swap(str[index], str[i]);
        }
    }
}
int main()
{
    char str[] = "ABCA"; 
    int n = strlen(str); 
    findPerm(str, 0, n); 
    std::cout << "way 2"<<'\n';
    printPerms("ABCA");
    //both are same
    return 0; 
}