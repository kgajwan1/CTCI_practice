//tower of hanoi
//re
#include<bits/stdc++.h>


void tower_of_Hanoi(int n_disk, int init_location, int tempLocation, int final_location)
{
    if( n_disk != 0 ) 
    {
        tower_of_Hanoi( n_disk-1, init_location, final_location, tempLocation );
        std::cout << init_location << "->" << final_location << std::endl;
        tower_of_Hanoi( n_disk-1, tempLocation, init_location, final_location );
    }
}


int main()
{
    int n_disk = 2;
    tower_of_Hanoi(n_disk, 1, 2, 3);
}
