//binary search for infinite array
#include <bits/stdc++.h>

int binarySearch(int *arr, int l, int h, int key )
{
    int mid = l+(h-l)/2;
    if (arr[mid] ==key)
        return mid;
    if (arr[mid]<key)
        return binarySearch(arr,mid+1,h,key);
    else
    {
        /* code */
        return binarySearch(arr,l,mid-1,key);
    }
}

int findposition(int *arr, int key)
{
    int l =0,h =1;
    int val = arr[0];
    while (val<key)
    {
        l = h;
        h*=2;
        val = arr[h];
    }
    return binarySearch(arr, l, h, key); 
}

int main()
{ 
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,  
                               140, 160, 170}; 
    int ans = findposition(arr, 90); 
    if (ans==-1) 
        std::cout << "Element not found"; 
    else
        std::cout << "Element found at index " << ans; 
    return 0; 
} 