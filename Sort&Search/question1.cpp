//sorted merge
//given 2 sorted array and large enough buffer 
//to store them, merge the arrays

#include<bits/stdc++.h>

void sortedmerge(int a[], int b[],int a_count ,int b_count)
{
    int  i = a_count-1;
    int j = b_count-1;
    int last_val = a_count+b_count-1;

    while(j>=0)
    {
        if(i >=0 && a[i]>=b[j])
            {
                a[last_val]= a[i];//copy element
                i--;
            }
            else {
                a[last_val] =b[j];
                j--;
            }
            last_val--;
    }
}

void printArray(int *arr, int n) { 
  std::cout << "Array A after merging B in sorted"
        " order : \n" ; 
  for (int i = 0; i < n; i++) 
   std:: cout << arr[i] << " "; 
}

int main() { 
  int a[] = {10, 12, 13, 14, 18,-1, -1, -1, -1, -1}; 
  int n = 5; 
  int size_a = 10; 
  int b[] = {16, 17, 19, 20, 22}; 
  int m = 5; 
  sortedmerge(a, b, n, m); 
  printArray(a, size_a); 
  return 0; 
} 