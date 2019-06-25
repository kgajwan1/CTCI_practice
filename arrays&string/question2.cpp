//CTCI question 2;
//check if s2 is permutation of s1
#include<bits/stdc++.h>
//there are 2 ways
//1: sort the array and do a string compare: O(nlogn), in place compare
//2: Make a character counter and map character to frequency (a permutation will have 
//   same number of characters as the original string) 
//sort is simpler to comprehend, but counter is more efficient O(n)

bool is_permutation_method1(std::string a,std::string b)
{
    if (a.length() != b.length())
    {
        return false;
    }
 //method 1 sort the strings   
    std::sort(a.begin(),a.end());
    std::sort(b.begin(),b.end());
        if (a.compare(b) != 0)
        {
            return false;
        }
        return true;
}

bool is_permutation_method2(std::string a,std::string b)
{
 //method 2 character counter
 //hell stops here
    if (a.length() != b.length())
    {
        return false;
    }   
    //assuming eascii
    int letters_counter[256] ={0};
    for (int i =0; i<a.length();i++)
    {
        //how would it work
        //eg. hello
        //a[0]=h, a[1]=e,a[2] = l, a[3] = l, a[4] =o
        //character counter
        //we increment here
        letters_counter[a[i]]++;
        //letter[a[0]] = 1,letter[a[1]] = 1, letter[a[2]] =1 letter[a[3]] =2,letter[a[4]] =1
        printf("%d",letters_counter[a[i]]);
    }
    for (int i =0; i<b.length();i++)
    {
        //we decreement here
        letters_counter[b[i]]--;
        printf("%d",letters_counter[b[i]]);
       // printf("%d",letters_counter[b[i]]);

        if(letters_counter[b[i]]<0)
            {return false;}
    }
    return true;
}

int main()
{
    //sort and compare
    std::string s1 = "Hello";
    std::string s2 = "Hlelo";
    //std::sort(s2.begin(),s2.end());
    std::string s3 = "oheol";
    std::string s4 = "hell";
   	std::cout << s1 <<" Is permutation of " << s2 << " : " << std::boolalpha << is_permutation_method1(s1,s2) <<std::endl;
    std::cout << s1 <<" Is permutation of " << s3 << " : " << std::boolalpha << is_permutation_method1(s1,s3) <<std::endl;
   	std::cout << s1 <<" Is permutation of " << s2 << " : " << std::boolalpha << is_permutation_method2(s1,s2) <<std::endl;
    std::cout << s1 <<" Is permutation of " << s4 << " : " << std::boolalpha << is_permutation_method2(s1,s4) <<std::endl;

    return 0;
}
