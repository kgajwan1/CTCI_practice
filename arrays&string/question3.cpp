/*
 * Cracking the coding interview Edition 6
 * Problem 1.3 URLify --> Replace all the spaces in a string with '%20'. 
 * Assumption : We have enough space to accomodate addition chars
 * Preferebly in place
 */

#include <iostream>
#include <cstring>

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

int main()
{
    char str[] = "Mr John Smith    ";
     std::cout << "Actual string   : " << str << std::endl;
     urlify(str,13);
     std::cout << "modified string   : " << str << std::endl;
}
