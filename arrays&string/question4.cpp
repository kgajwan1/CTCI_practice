//question 4 palindromic permutation 
//given a string, write a function to check if it is permutation of palindrome or not 
//ignore casing, non letter characters
//approaches
//approach 1: base philosophy
// if string has even number of characters, all characters should have even count
//if strimg has odd number of characters, then only one character should have odd count
//work with Hash map

/*utility to count frequency */
#include<bits/stdc++.h>

int get_char_index(char c)
{
    int idx = -1;
    if (c > 'a' &&  c < 'z' )
    {
        idx = c - 'a';
    }
    else if (c > 'A' && c < 'z')
    {
        idx = c - 'A';
    }
    return idx;

}

void count_frequency (const std::string &str, int *freq )
{
    int idx;
    for (const char &c : str)
    {
        int idx = get_char_index(c);
        if (idx != -1)
        {
            freq[idx]++;
        }
    }

}
//method 1
bool isPermPalin_method1( const std::string &str )
{
    int freq[26] = {0};
    count_frequency(str , freq);
    bool oddAppeared = false;
    for ( int i = 0 ; i < 26; ++i ) {
        if ( freq[i] % 2  && oddAppeared ) {
            return false;
        } else if ( freq[i] % 2 && !oddAppeared ) {
            oddAppeared = true;
        }
    }
return true;
}

//Method 2
//minor optimization
//in place table making
bool isPermPalin_method2( const std::string &str )
{
    int freq[26] = {0};
    //index
    int idx = 0;
    int odd_count = 0;
    //& is not necessary
    for ( const char &c : str )
    {
        idx = get_char_index(c);
        if(idx != -1)
        {
            freq[idx]++;
        }
        if ( freq[idx] % 2 ) 
            {   

                ++odd_count;
            
            } else {
                --odd_count;
            }
    }
return (odd_count<=1);
}

int main(){
     std::string str("Tact Coa");
         std::cout << "Does \"" << str << "\"  has a string whose permutation is a pallindrome? "
              << "( 1 for true, 0 for false ) : ";
        std::cout << "Method 1:" << isPermPalin_method1( str ) << std::endl;
        std::cout << "Method 2:" << isPermPalin_method2( str ) << std::endl;

}
