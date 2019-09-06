//Search an element in a sorted and rotated array

#include <bits/stdc++.h>

int pivot_binarysearch(int arr[],int low, int high, int key)
{

    if(low>high)
        return -1;
    int mid = (low+high)/2; 
    if( arr[mid] == key)
        return mid;
    /* If arr[l...mid] is sorted */
    if(arr[low]<= arr[mid])
    {
        if(key>= arr[low] && key <= arr[mid] )
        {
            return pivot_binarysearch(arr,low,mid-1,key);
        }
        return pivot_binarysearch(arr,mid+1,high,key);
    }
    if(key>= arr[mid] && key <= arr[high])
        {
            return pivot_binarysearch(arr,mid+1,high,key);
        }

    return pivot_binarysearch(arr, low, mid-low,key);
}

int main() 
{ 
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int key = 6; 
    int i = pivot_binarysearch(arr, 0, n-1, key); 
  
    if (i != -1) 
    std::cout << "Index: " << i ; 
    else
    std::cout << "Key not found"; 
} 