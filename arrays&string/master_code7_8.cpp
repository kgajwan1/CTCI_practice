//Question 7
//code for programs 7 and 8 together, AS MY PRACTICE
/*  matrix :
1 2 3
4 5 6
7 8 9
Rotated matrix  by 90(anticlockwise):
3 6 9
2 5 8
1 4 7 


matrix :
1 2 3
4 0 6
7 8 9
nullified matrix
1 0 3
0 0 0
7 0 9
*/

//temp variable

#include<bits/stdc++.h>

void print_Matrix(int **matrix, int n)
{
    for ( int i = 0; i < n; ++i ) {
		for( int j = 0; j <	 n; ++j ) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Rotate_matrix_anticlockwise(int **matrix, int n)
{
	for (int i = 0;i<n/2;i++)
	{
		for(int j =0;j<n-i-1;j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][n-i-1];
			matrix[j][n-i-1]= matrix[n-i-1][n-j-1];
			matrix[n-i-1][n-j-1]= matrix[n-j-1][i];
			matrix[n-j-1][i] = temp;
		}
	}
}

//this method is better, i will redo it
void helper_transpose(int **matrix, int N)
{
	for( int i = 0; i < N; ++i ) {
		for( int j = i+1; j < N; ++j ) {
			if ( i != j ) {
				std::swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
}

void helper_reverse( int * column, int N ) {
	for ( int i = 0; i < N/2; ++i ) {
		std::swap(column[i], column[N-i-1]);
	}
}

void Rotate_matrix_clockwise(int ** matrix, int N) {
	//transpose matrix
	helper_transpose(matrix, N);
	// reverse each row
	for ( int i = 0; i < N; ++i ) {
		helper_reverse(matrix[i], N);
	}
}


//program 8: nullify matrix
void nullify_colums(int **matrix, int n, int column)
{
	for (int i=0;i<n;i++)
	{
		matrix[i][column]=0;
	}

}

void nullify_rows(int **matrix, int n, int row)
{
	for(int i =0;i<n;i++)
	{
		matrix[row][i]=0;
	}
}
//bunch of flags and stuff
void nullify_matrix(int **matrix, int row, int column)
{
	//for row 1
		bool first_row = false;
		for (int i =0;i<row;i++)
		{
			if(matrix[0][i] ==0)
			{
				first_row =true;
			}
		}

		for( int i = 1; i < column; ++i ) {
		bool nullifyThisRow = false;
		for ( int j = 0; j < row; ++j ) {
			if ( matrix[i][j] == 0 ) {
				matrix[0][j] = 0;
				nullifyThisRow = true;
			}
		}
		if (nullifyThisRow)
			nullify_rows(matrix, row, i);
	}
	for ( int j = 0; j < row; ++j ) {
		if ( matrix[0][j] == 0 ) {
			nullify_colums(matrix, column,  j);
		}
	}

	//now first row
	if ( first_row ) {
		nullify_rows(matrix, row, 0);
	}
}
int main() {
	int N;
	std::cout << "Enter N for NxN matrix:";
	std::cin >> N;
	int ** matrix = new int*[N];
	for ( int i = 0; i < N; ++i ) {
		matrix[i] = new int[N];
	}

	for ( int i = 0; i < N; ++i) {
		for ( int j = 0; j < N; ++j ) {
			std::cin >> matrix[i][j];
		}
	}

	std::cout << " matrix :\n";
	print_Matrix(matrix, N);
	std::cout << "Rotated matrix  by 90(anticlockwise):\n";
	Rotate_matrix_anticlockwise(matrix, N);
	print_Matrix(matrix, N);
    std::cout << "Rotated matrix  by 90(clockwise):\n";
	Rotate_matrix_clockwise(matrix, N);
	print_Matrix(matrix, N);
	std::cout << "nullified matrix:\n";
	nullify_matrix(matrix, N, N);
	print_Matrix(matrix,N);
	return 0;
}
