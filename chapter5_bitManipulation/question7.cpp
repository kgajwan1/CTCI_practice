//question 7
//pairwise swap

//use mask
//swap bit 0 and 1, 2 &3 etc
#include<bits/stdc++.h>
int swapBits(int n)
{
    //rightshift all odd and leftshift all even
    return (((n & 0xaaaaaaaa)>>1) | ((n & 0x55555555)<<1));
}
int main()
{
    int a = 14;
    std::cout << swapBits(a);
}

