//all examples from 1-6 in a same program
//rest are matrix with user input, so i will make another version
//program 1
//isUnique
#include <bits/stdc++.h>
//program 1
//if no ds, sort and compare
bool isUnique(std::string s1)
{
    //eascii which has length 256
     if(s1.length() > 256)
    {
        return false;
    }
    //this works
    // std::vector<bool> char_set(256);
    //why does this not work?
    //bool  char_set[256];
    //coz i fckin forgot to initialize it doofus
    bool  char_set[256]= {false};
    for (int i =0; i< s1.length();i++)
    {
        int val = s1[i];
        if(char_set[val])
        {
            std::cout<<s1[i]<<"  "<<'\n';
            return false;
        }
    	char_set[val] = true;
    }
    return true;
}

bool isUniqueNoDs(std::string s1)
{
    if(s1.length() > 256)
    {
        return false;
    }
    std::sort(s1.begin(),s1.end());
    for(int i =1;i<=s1.length();i++)
    {
        if(s1[i-1] == s1[i])
        {
            return false;
        }
    }
    return true;
}

//program 2
//CTCI question 2;
//check if s2 is permutation of s1
//2 ways 
//1. sort and compare characters, in place

bool isPermOf(std::string s1, std::string s2)
{
    if(s1.length() != s2.length())
    {
        return false;
    }
    std::sort(s1.begin(),s1.end());
    std::sort(s2.begin(),s2.end()); 
    for (int i =0;i<s1.length();i++)
    {
        if(s1[i] != s2[i])
        {
            return false;
        }
    }
    return true;
}
//method 2 : make a hash map mapping character freq to character
bool isPermOf_M2(std::string s1, std::string s2)
{
    if(s1.length() != s2.length())
    {
        return false;
    }
    int letters[256];
    for (int i =0;i<s1.length();i++)
    {
        letters[s1[i]]++;
    }
    for (int i =0;i<s1.length();i++)
    {
        letters[s2[i]]--;
        if(letters[s2[i]] < 0)
        {
            return false;
        }
    }
    return true;
}

/*
 * Cracking the coding interview Edition 6
 * Problem 1.3 URLify --> Replace all the spaces in a string with '%20'. 
 * Assumption : We have enough space to accomodate addition chars
 * Preferebly in place
 */
int countSpace(std::string st, int len)
{ 
    int spaceCount = 0;
    for (int i =0;i<len;i++)
    {
        if(st[i] == ' ')
        {
            spaceCount++;
        }
    }
    return spaceCount;
}
void urlify(char *str, int len)
{
    //count number of spaces
    int num_spaces = countSpace(str,len);
    //extended length here
    int e_len = len + (2*num_spaces);
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


//question 4 palindromic permutation 
//given a string, write a function to check if it is permutation of palindrome or not 
//ignore casing, non letter characters
//approaches
//approach 1: base philosophy
// if string has even number of characters, all characters should have even count
//if strimg has odd number of characters, then only one character should have odd count
//work with Hash map
int getCharIndex(char c)
{
    int idx = -1;

    if(c>='a' && c <='z')
    {
        idx = c -'a';
    }
    else if (c >'A' && c <'Z')
    {
        idx = c - 'A';
    }
    return idx; 
}
bool isPermPalin(const std::string &str)
{

    //freq array
    int freq[26] = {0};
    int idx = 0;
    int odd_count =0;
    for (const char &c : str) 
    {
        idx = getCharIndex(c);
        if(idx != -1)
        {
            freq[idx]++;
        }
        if (freq[idx]%2)
        {
            odd_count++;
        }
        else 
        {
            odd_count--;
        }
    }
    return (odd_count<=1);
}

//CTCI question 5
//one away: check if the new word is one edit away from old one
//pale, ple -> true
//pale, bale -> true
//aple, apple -> true
//apple, aple -> true
//method: part 1: check if one addition away, one removal away (same method)

//part 2, one character change
bool isCharChange(std::string s1, std::string s2)
{
    bool founddifference = false;
    for(int i = 0;i<s1.length();i++)
    {
        if (s1[i] != s2[i])
        {
            if(founddifference)
            {
                return false;
            }
            founddifference=true;
        }
    }
    return true;
}
//here loop goes
//ohell, hell 
bool oneInsertAway(std::string s1, std::string s2)
{
    int index1 =0;
    int index2 = 0;
    while(index1 < s1.length() && index2 < s2.length())
    {   
        //0<5 and 0<4
        if(s1[index1] != s2[index2])
        {
             if(index1 != index2)
            {
                return false;
            }
            index2++;
        }
        else
        {
            index1++;
            index2++;
        }
    }
    return true;
}
bool isOneEditAway(std::string s1,std::string s2)
{
    if(s1.length() == s2.length())
    {
            return isCharChange(s1,s2);
    }
    else if(s1.length()== (s2.length()-1))
    {
            return oneInsertAway(s1,s2);
   
    }
    else if (s2.length() == (s1.length() -1) )
    {
            return oneInsertAway(s2,s1);
    }
    return false;
}

//string builder example
//stringcompress

std::string stringcompress(std::string str)
{
    size_t original_length = str.length();
	if(original_length < 2)
	{
		return str;
	}
	std::string out{""};

    int count =1;
    for (int i = 1;i<=str.length();i++)
    {
        if(str[i-1]== str[i])
        {
            count++;
        }
        else 
        {
        	out+=str[i-1];
			out += std::to_string(count);
			count =1;
		}
    }
    out+=str[str.length() -1];
    out+=std::to_string(count);
    if(out.length() <= str.length())
    {
        return out;
    }
    return str;
}
int main()
{
    std::string s1 = "nachos";
    std::string s2 = "hello";
    std::string s3 = "ohell";
    char s4[] = "ohe ll  ";
    std::string s5 = "osomm";
    std::string s6 = "hell";
    std::string s7 = "helli";
  	std::string str = "aaaaaaaaaaaaabbbbbbbbbbbfyyyyyyyyyyytho";
	std::string out = stringcompress(str);
	//std::cout << "Enter a string:\n";
	//std::cin >> str;
	// int spacec = countSpace(s4,6);
    //std::cout << spacec <<'\n';
    std::cout<<s1<<"  "<<std::boolalpha<< isUnique(s1)<<'\n';
    std::cout<<s2<<"  "<<std::boolalpha<< isUnique(s2)<<'\n';
    std::cout<<s1<<"  "<<std::boolalpha<< isUniqueNoDs(s1)<<'\n';
    std::cout<<s2<<"  "<<std::boolalpha<< isUniqueNoDs(s2)<<'\n';
    //Q4 done
    std::cout<<s5<<" is it permutation of palindrome? "<<std::boolalpha<< isPermPalin(s5)<<'\n';
    std::cout<<s2 <<" and "<<s3 <<"  permutation of each other?"<<"  "<<std::boolalpha<< isPermOf(s2,s3)<<'\n';
    std::cout<<s1 <<" and "<<s3 <<"  permutation of each other?"<<"  "<<std::boolalpha<< isPermOf(s1,s3)<<'\n';
    std::cout<<s2 <<" and "<<s3 <<"  permutation of each other?"<<"  "<<std::boolalpha<< isPermOf_M2(s2,s3)<<'\n';
    std::cout<<s1 <<" and "<<s3 <<"  permutation of each other?"<<"  "<<std::boolalpha<< isPermOf_M2(s1,s3)<<'\n';
    //Q3 over
    urlify(s4,6);
    std::cout<<s4<<'\n';
    //Q5 over
    std::cout<<s3 <<" and "<<s6 <<" one edit from each other?"<<"  "<<std::boolalpha<< isOneEditAway(s3,s6)<<'\n';
    std::cout<<s2 <<" and "<<s7 <<" one edit from each other?"<<"  "<<std::boolalpha<< isOneEditAway(s2,s7)<<'\n';
    std::cout<<s2 <<" and "<<s7 <<" one edit from each other?"<<"  "<<std::boolalpha<< isOneEditAway(s7,s2)<<'\n';
    //Q6
    if (str.compare(out)) {
		std::cout << str << " can be compressed to " << out << std::endl;
	} else {
		std::cout << str << " can not be compressed\n";
	}

}
