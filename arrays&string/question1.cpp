//CTCI question 1
//implement algorithm to determo=ine if string has all unique characters. 
//What if you can not use any additional data structures

//Is it ASCII, Extended ASCII or Unicode?
//ASCII has 128 chars, EASCII has 256,Unicode, welll 137K, Leave it

#include<bits/stdc++.h>

bool isUnique (std::string str)
{
  //question comes to play here
    if(str.length() > 256)
    {
        return false;
    }
    std::vector<bool> char_set(256);
		for (int i = 0; i < str.length(); i++){
			int val = str[i];
           // std::cout <<val<<'\n';
            //if bit is already set to 1, return false
            if (char_set[val]){
				return false;
			}
            //setting flag to 1
			char_set[val] = true;
		}
return true;
}


bool isUniquebitvec(std::string str)
{
 if(str.length() > 256)
    {
        return false;
    }
    	std::bitset<256> bits(0);
		for (int i = 0; i < str.length(); i++){
			int val = str[i];
            //if bit is already set to 1
			if (bits[val])
            {
				return false;
			}
			bits[val] = true;
		}
return true;
}

bool isUniqueNoDS(std::string str)
{
    std::sort(str.begin(),str.end());
    for(int i =0;i<str.length();i++)
    {
        if (str[i]==str[i+1]){
            return false;
        }

    }
    return true;

}

int main()
{
   std::string str="Helol";
   std::string str2="Helo";
   //std::boolalpha converts 0 and 1 to false and true respectively
    	std::cout << str << " : " << std::boolalpha << isUnique(str) <<std::endl;
        //std::cout << str2 << " : " << std::boolalpha << isUnique(str2) <<std::endl;
        std::cout << str << " : " << std::boolalpha << isUniquebitvec(str) <<std::endl;
        std::cout << str << " : " << std::boolalpha << isUniqueNoDS(str) <<std::endl;
}

