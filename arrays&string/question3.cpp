/*
 * Cracking the coding interview Edition 6
 * Problem 1.3 URLify --> Replace all the spaces in a string with '%20'. 
 * Assumption : We have enough space to accomodate addition chars
 * Preferebly in place
 */

#include<bits/stdc++.h>

/*
 * Function : urlify
 * Args     : string long enough to accomodate extra chars + true len 
 * Return   : void (in place transformation of string)
 */

void urlify(char *str, int len)
{
    //count number of spaces
    int num_spaces = 0;
    for (int i = 0; i< len; i++)
    {
        if (str[i] == ' ')
        {num_spaces++;}
    }
    //extended length here
    int e_len = len + (2*num_spaces);
    std::cout<<e_len<<'\n';
    int i = e_len-1;
    for (int j = len-1;j>=0;j--)
    {
        if (str[j] != ' ')
        {
            str[i--] = str[j];
        }
        else 
        {
            str[i--]= '0';
            str[i--]= '2';
            str[i--]= '%';
        }
    }
}
//using inbuilt libraries
//you 
std::string urLify2(char *str)
{

        const auto target = std::regex{ " " };
        const auto replacement = std::string{ "%20" };
        
        return std::regex_replace( str, target, replacement ) ;
}

int main()
{
    char str[] = "Mr John Smith    ";
    char str21[] = "Mr Delicious Nachos";
     std::cout << "Actual string   : " << str << std::endl;
     urlify(str,13);
     std::cout << "modified string way 1   : " << str << std::endl;
     std::string str2 = urLify2(str21);
     std::cout << "modified string way 2  : " << str2 << std::endl;

}
