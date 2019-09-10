//sort in wave

#include <bits/stdc++.h>


void sortinWave(int *arr,int n)
{
    for (int i = 0;i<n ;i+=2)
    {
        if (i>0 && arr[i-1]>arr[i])
        {
            std::swap (arr[i],arr[i-1]);
        }
        if(i<n-1 && arr[i]< arr[i+1])
        {
            std::swap (arr[i],arr[i+1]);
        }
    }
}
int main()
{
     int arr[] = {5,3,1,2,3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    sortinWave(arr, n); 
    for (int i=0; i<n; i++) 
       std::cout << arr[i] << " "; 
    return 0; 
}