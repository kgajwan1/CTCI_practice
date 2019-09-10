/*
You have an array with all the numbers from 1 to N, where N is at most 32,000. 
The array may have duplicate entries and you do not know what N is. 
With only 4 kilobytes of memory available, how would you print all duplicate elements in the array? 
*/
//use a bit vector
/*
We have 4 Kilobytes of memory which means we can address up to 8 * 4 * 2^10 bits. 
Note that 32 * 2^10 bits is greater than 32000. 
We can create a bit with 32000 bits, where each bit represents one integer.
*/
#include<bits/stdc++.h>

class bitarray{
    int *arr;
    public:
    bitarray() {}

    bitarray(int n)
    {
        arr = new int [(n>>5) +1];
        // std::cout <<"here\n";
       // std::cout << arr;
    }

    bool get(int pos) 
    {
        int index = (pos >> 5); //shift bit
        int bitNo = (pos & 0x1F); //mask
        bool val = arr[index] & (1 << bitNo);
        std::cout <<'\n'<<val;
        return (arr[index] & (1 << bitNo)) != 0; 
    }

    void set(int pos) 
    { 
        // Find index of bit position 
        int index = (pos >> 5); 
        // Set bit number in arr[index] 
        int bitNo = (pos & 0x1F); 
        arr[index] |= (1 << bitNo); 
    } 
    void checkDuplicates(int arr[], int n) 
    { 
        // create a bit with 32000 bits 
        bitarray ba = bitarray(320000); 
  
        // Traverse array elements 
        for (int i = 0; i < n; i++) 
        { 
            // Index in bit array 
            int num = arr[i]; 
  
            // If num is already present in bit array 
            if (ba.get(num)) 
                std::cout << num << " "; 
  
            // Else insert num 
            else
                ba.set(num); 
        } 
    } 
};

//using bitset, i'll implement it in implementation
/*int *method2(int *arr,int size)
{
    std::bitset<32000> b;

}*/
int main()
{
    int arr[] = {1, 5,5, 1, 10, 12, 10}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    bitarray obj =  bitarray(); 
    obj.checkDuplicates(arr, n); 
    return 0; 

}