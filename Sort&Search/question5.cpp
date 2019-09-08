//find a algorithm to 

#include<bits/stdc++.h>

int sparseSearch(std::string *arr,int low, int high, std::string str)
{
    if(low > high)
        return -1;
    int mid = (high + low)/2;
    //std::cout << mid;

    if(arr[mid] =="")
        {
            int left = mid -1;
            int right = mid +1;

    
    while (1)
    {
        if (left < low && right > high)
            return -1;
        if(left  >= low && arr[left] != ""){
            mid = left ;
            break;
           }
        else if (right <= high && arr[right]!= ""){
             mid = right;
             break;
           }
        left --;
        right++;
        }
    }
     if(arr[mid] == str)
        return mid;
    else if(arr[mid]> str)
        return sparseSearch(arr, low, mid-1, str);
    else
        return sparseSearch(arr, mid+1, high, str);    
      
}

int main()
{
    std::string arr[] = {"at", "", "", "", "ball", "bam", "cam",  
                      "car", "", "", "dad", "",""}; 
    std::string x = "ball"; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    int index = sparseSearch(arr, 0, n-1,x); 
    if (index != -1) 
        std::cout << x << " found at index " << index << "\n"; 
    else
        std::cout << x << " not found\n"; 
  return 0; 
}