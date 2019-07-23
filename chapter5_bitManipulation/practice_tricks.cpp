//all tricks fromm GFG, practice

#include<bits/stdc++.h>
//compute all xor from 1 to n
/*
1- Find the remainder of n by moduling it with 4.
2- If rem = 0, then xor will be same as n.
3- If rem = 1, then xor will be 1.
4- If rem = 2, then xor will be n+1.
5- If rem = 3 ,then xor will be 0. 
*/
int computexor(int n)
{
    if (n%4 == 0)
        return n;
    if (n%4 == 1)
        return 1;
    if (n%4 == 2)
        return n+1;
    else 
        return 0;
}
/*
Equal Sum and XOR
Given a positive integer n, 
find count of positive integers i such that 0 <= i <= n and n+i = n^i
Input n = 12
Output: 4
12^i = 12+i hold only for i = 0, 1, 2, 3
for i=0, 12+0 = 12^0 = 12
for i=1, 12+1 = 12^1 = 13
for i=2, 12+2 = 12^2 = 14
for i=3, 12+3 = 12^3 = 15
 */
//trick

//n + i = n ^ i implies n & i = 0

//Program to find whether a no is power of two
//use math log
//question 3
bool power2(int n) 
{
    if (n ==0)
        return false;

    return  (floor (log2(n))== ceil(log2(n)));
}

//do & with n & n-1
bool ispowerof2(int n)
{
    if(n == 0)
        {
            return false;
        }
    return !(n& (n-1));
}

int eqSumAndXor(int n)
{
    int unset_bits =0;
    while (n)
    {
        if((n & 1) == 0)
            unset_bits++;
        n = n>>1;
    }
    return 1<<unset_bits;
    //or pow(2,unset_bits)
    
}
 int findXor(int set[], int n)
 {
     if (n>1)
        return 0;
     return set[0];
 }
 //question 7
 //The Quickest way to swap two numbers:
 //freakin use std::swap 
 void Scwap(int *x, int *y)
 {
     if (x == y)
            return;
   *x = *x + *y; // x now becomes 15 (1111) 
    *y = *x - *y; // y becomes 10 (1010) 
    *x = *x - *y; 
   // printf("%d %d  ",x,y);
 }

//flip bits of a  number
void invertBits(int number)
{
    int x = log2(number)+1;
    std::bitset<32> b(number);

    for (int i = 0;i<x;i++)
        b.flip(i);
    std::cout<< "flipped number  "<<b.to_ulong()<<'\n';
}

int main()
{
    //Input : n = 6
    //Output : 7
    // 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6  = 7
    //trick 1
    int n = 6;
    int n1 = 101;
    int n2 = 102;

    int n3 = computexor(n);
    int n4 = computexor(n1);
    int n5 = computexor(n2); 
    std::cout<<"compute all xor from 1 to n\n";
    std::cout <<" n: "<< n <<" value " << n3 <<"\n"<<" n1: "<< n1 << " value "<<n4 <<"\n"<< " n2: " << n2 << " value " <<n5;
    //eqSumAndXor
    int q21 = eqSumAndXor(12);
    int q22 = eqSumAndXor(n2);
    int q23 = eqSumAndXor(n3);
    
    //question 4
    int Set[] = {1, 2, 3}; 
    int len = sizeof(Set)/sizeof(Set[0]); 
    //question 6
    auto number = 0b0111;

    std::cout<<"\n" << "12" << ": "<< q21 <<"\n";
    std::cout << n2 << ": "<< q22<<"\n";
    std::cout << n3 << ": "<< q23 <<"\n";    
    std::cout <<"12  "<< std::boolalpha<< power2(12)<<"\n";
    std::cout <<"16  "<< std::boolalpha<< power2(16)<<"\n";
    std::cout <<"63  "<< std::boolalpha<< power2(63)<<"\n";
    std::cout <<"12  "<< std::boolalpha<< ispowerof2(12)<<"\n";
    std::cout <<"16  "<< std::boolalpha<< ispowerof2(16)<<"\n";
    std::cout <<"63  "<< std::boolalpha<< ispowerof2(63)<<"\n";
    std::cout << "XOR of XOR's of all subsets is "<< findXor(Set, len)<<"\n"; 
    //binary to decimal
    std::cout <<"number  "<< number <<'\n'; 
    std::cout<< "before swap"<<'\n';
    std::cout << n << " " << n1<<'\n';
    std::cout <<"after swap"<<'\n';    
    
    //use pointers
    Scwap(&n,&n1); 
    std::cout <<n <<": "<<n1<<'\n';
    invertBits(n1);
    invertBits(n);
}
