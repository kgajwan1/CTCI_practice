//question 1 
//bits manipulation
//you are gven 2 32 bits integers N and M, and 2 bit positions i and j. 
//Write a  method to insert M into N such tthat M starts at bit J and ends at bit i
//example 
//N = 10000000000
//M =  10011
//i = 2, j =6
//output  N = 10001001100 // 1100 in int, it aint array

#include <bits/stdc++.h>

int updatebits(int n, int m, int i, int j)
{
    if(i>j || i<0 ||  j>=32)
    {
        return 0;
    }
    //create a mask
    int allones = ~0;
    //1's before j, then 0's left
    int left = j <   31 ? (allones << (j+1)):0;
    //1's after position 1, right = 00000011
    int right  =((1<<i)-1);
    int mask = (left | right);
    int n_cleared = n & mask;
    int m_shifted = m << i;

    return (n_cleared | m_shifted);

}

int main()
{
    
    auto result = updatebits(0b10000000000, 0b10011, 2, 6);
    //1024 input, 1100 output
    std::cout << result;

}