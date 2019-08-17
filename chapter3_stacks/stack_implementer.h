#include<climits>
#include<iostream>//to check /debug

class nStacks{
    //private:
    int *arr;// array
    int *top;// top portion
    int *next;//next entry in all stacks and free list
    
    int n, k; //n & k
    int free;// for index of free list
    
    public:
    nStacks(int k, int n );
    void push(int item, int sn); 
    int pop(int sn); 
    bool isFull(); 
    bool isEmpty(int sn) {return (top[sn] == -1);}

};

bool nStacks::isFull()
{
 return (free == -1);
}

nStacks::nStacks(int k_1,int n_1)
{
    k = k_1;
    n = n_1;
    arr = new int [n];
    top = new int [k];
    next = new int [n];

    for (int i = 0;i<k;i++)
    {
        top[i]= -1;
    }
    free =0;
        // Initialize all spaces as free 
    for (int i = 0;i<n-1;i++)
    {
        next[i] = i+1;
    }
    next[n-1] = -1; 
}

void nStacks::push(int item1,int serial_num)
{
    if(isFull())
    {
        std::cout<<"Stack overflow\n";
        return ;
    }
    int i = free;
    free = next [i];
    next [i] = top[serial_num];
    top[serial_num] = i;
    arr[i]= item1; 
}

int nStacks::pop(int serial_number)
{
    if(isEmpty(serial_number))
    {
        std::cout <<"empty stack\n";
        return 0;
    }
    int i = top[serial_number];
    top[serial_number]= next[i];
    next[i] = free;
    free = i;
    return arr[i]; 
}

