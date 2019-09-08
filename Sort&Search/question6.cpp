//sort a 20 GB file , not on main memory
//way 1 use merge sort
//I do not have 20 Gb file to 
//sort, So I am just doing merge sort of 2 arrays
/*as per wiki
    1. Read 100 MB of the data in main memory and sort by some conventional method, like quicksort.
    2. Write the sorted data to disk.
    3. Repeat steps 1 and 2 until all of the data is in sorted 100 MB chunks (there are 
    900MB / 100MB = 9 chunks), which now need to be merged into one single output file.
    4. Read the first 10 MB (= 100MB / (9 chunks + 1)) of each sorted chunk into input buffers 
    in main memory and allocate the remaining 10 MB for an output buffer. 
    (In practice, it might provide better performance to make the output buffer 
    larger and the input buffers slightly smaller.)
    5. Perform a 9-way merge and store the result in the output buffer. 
    Whenever the output buffer fills, write it to the final sorted file and empty it. 
    Whenever any of the 9 input buffers empties, fill it with the next 10 MB of its 
    associated 100 MB sorted chunk until no more data from the chunk is available.
    This is the key step that makes external merge sort work externally -- 
    because the merge algorithm only makes one pass sequentially through each of 
    the chunks, each chunk does not have to be loaded completely; rather, 
    sequential parts of the chunk can be loaded as needed.
*/
#include<bits/stdc++.h>

void merge(int *arr, int l, int m,int r)
{
    int i,j,k;
    //lower ,middle, right 
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];

    for ( i = 0; i< n1;i++)
    {
        L[i] = arr[i+l];
    }
    for ( j = 0; j< n2;j++)
    {
        R[j] = arr[m+1+j];
    } 
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l;

    while (i<n1 && j< n2)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
    k++;
    }
    while (i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (k<n2)
    {
        /* code */
        arr[k] = R[j];
        j++;
        k++;
    }  
}

void mergeSort(int *arr, int l,int r)
{
    if(l<r)
    {
        int m = l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        std::cout<< A[i]<<" "; 
    std::cout <<'\n'; 
} 

int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    std::cout <<"Given array is \n"; 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    std::cout <<"\nSorted array is \n"; 
    printArray(arr, arr_size); 
    return 0; 
}   