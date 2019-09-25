//famous 8 queens problem
#define N 8
#include<bits/stdc++.h>

void printSolution(int board[N][N])
{
    for (int i=0;i<N;i++)
    {
        for (int j =0;j<N;j++)
        {
            std::cout<<board[i][j]<<" "; 
        }
    std::cout<<'\n';
    }
}

bool isSafe(int board[N][N],int row, int column)
{
    int i,j;
        /* Check this row on left side */
    for ( i =0;i<column;i++)
        if(board[row][i])
            return false;
    for ( i= row,j= column;i>=0&& j>=0;i--,j--)
        if(board[i][j])
            return false;
     for (i = row, j = column;j>=0&& i<N;i++,j--) 
        if (board[i][j]) 
            return false; 
    return true;
}

bool solveNQ(int board[N][N],int col)
{
    if(col>=N)
    {
        return true;
    }
    for(int i =0;i<N;i++)
    {
        if(isSafe(board,i,col))
        {
            board[i][col] =1;
         if (solveNQ(board, col + 1)) 
                return true; 
        board[i][col] = 0; // BACKTRACK 
        }  
    }
    return false; 
}
int main()
{
    int board[N][N] = { { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 } }; 
  
    if (solveNQ(board, 0)== false) { 
        std::cout<<"Solution does not exist\n"; 
    } 
    printSolution(board); 
}