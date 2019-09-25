#include<iostream> 
 
// Dimentions of paint screen 
#define M 8 
#define N 8 
  
// A recursive function to replace previous color 'previous_color' at  '(x, y)'  
// and all surrounding pixels of (x, y) with new color 'new_color' and 
void floodFillUtil(int screen[][N], int x, int y, int previous_color, int new_color) 
{ 
    // Base cases 
    if (x < 0 || x >= M || y < 0 || y >= N) 
        return; 
    if (screen[x][y] != previous_color) 
        return; 
  
    // Replace the color at (x, y) 
    screen[x][y] = new_color; 
  
    // Recur for north, east, south and west 
    floodFillUtil(screen, x+1, y, previous_color, new_color); 
    floodFillUtil(screen, x-1, y, previous_color, new_color); 
    floodFillUtil(screen, x, y+1, previous_color, new_color); 
    floodFillUtil(screen, x, y-1, previous_color, new_color); 
} 
  
// It mainly finds the previous color on (x, y) and 
// calls floodFillUtil() 
void floodFill(int screen[][N], int x, int y, int new_color) 
{ 
    int previous_color = screen[x][y]; 
    floodFillUtil(screen, x, y, previous_color, new_color); 
} 
  
// Driver program to test above function 
int main() 
{ 
    int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}, 
                     }; 
    int x = 2, y = 1, new_color = 3; 
    floodFill(screen, x, y, new_color); 
  
    std::cout << "Updated screen after call to floodFill: \n"; 
    for (int i=0; i<M; i++) 
    { 
        for (int j=0; j<N; j++) 
           std::cout << screen[i][j] << " "; 
        std::cout << '\n'; 
    } 
} 