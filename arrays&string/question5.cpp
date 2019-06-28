//CTCI question 5
//one away: check if the new word is one edit away from old one
//pale, ple -> true
//pale, bale -> true
//aple, apple -> true
//apple, aple -> true
//method: part 1: check if one addition away, one removal away (same method)
//part 2, one character change

#include<bits/stdc++.h>

bool oneEditReplace(std::string s1, std::string s2)
{
    bool founddifference = false;
    for (int i = 0; i< s1.length();i++)
    {
       // std::cout <<s1[i]<<'\n';
        if(s1[i] != s2[i])
        {
            if (founddifference)
            {
                return false;
            }
            founddifference = true;
        }
    }
    return true;
}

bool oneEditInsert(std::string s1, std::string s2)
{
    int index1 = 0;
    int index2 = 0; 
    while (index2 < s2.length() && index1 < s1.length())
    {
        if (s1[index1] != s2[index2])
        {
            if(index1 != index2)
            {
                return false;
            }
            index2++;
        }
        else {
            index1++;
            index2++;
        }
    }
    return true;
}
bool oneEditAway(std::string s1, std::string s2)
{
    if (s1.length() == s2.length())
    {
        return oneEditReplace(s1,s2);
    }
    else if(s1.length()+1 == s2.length())
    {
        return oneEditInsert(s1,s2);
    }
    else if (s1.length()-1 == s2.length())
    {
        return oneEditInsert(s2,s1);
    }
    return false;
}


int main()
{
    std::string s1 = "mary";
    std::string s2 = "mry";
    std::string s3 = "vary";
    std::cout << s1 << "  " <<s3<<"  "<< std::boolalpha<< oneEditAway(s1,s3)<<'\n';
    std::cout << s1 << "  " <<s2<<"  "<< std::boolalpha<< oneEditAway(s1,s2)<<'\n';
}
