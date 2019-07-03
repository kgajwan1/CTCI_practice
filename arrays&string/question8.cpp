//CTCI question 8 , Arrays and strings
//zero matrix 
//if a m*n matrix has a zero row, set that row and column to zero
//EG
/*
Input
1 2 3
4 0 5
6 7 8
Output
1 0 3
0 0 0
6 0 8 */
//method , use a bool var flag
//O(mn atleast)

//nullify helpers

#include<bits/stdc++.h>

void nullify_rows(int **matrix, int n, int row )
{
    for (int i =0;i<n;i++)
    {
        matrix[row][i]=0;
    }
}

void nullify_column(int **matrix, int n, int column )
{
    for (int i =0;i<n;i++)
    {
        matrix[i][column]=0;
    }
}
void nullifyMatrix(int ** matrix, int M, int N)
{
	bool firstRow = false;

	//first row
	for( int i = 0; i < N; ++i ) {
		if ( matrix[0][i] == 0 ) {
			firstRow = true;
			break;
		}
	}

	//rest of the matrix
	for( int i = 1; i < M; ++i ) {
		bool nullifyThisRow = false;
		for ( int j = 0; j < N; ++j ) {
			if ( matrix[i][j] == 0 ) {
				matrix[0][j] = 0;
				nullifyThisRow = true;
			}
		}
		if (nullifyThisRow)
			nullify_rows(matrix, N, i);
	}

	//now we know which column to be nullify using information stored in previous step.
	//cols first
	for ( int j = 0; j < N; ++j ) {
		if ( matrix[0][j] == 0 ) {
			nullify_column(matrix, M,  j);
		}
	}

	//now first row
	if ( firstRow ) {
		nullify_rows(matrix, N, 0);
	}

}




void print_Matrix( int ** matrix, int M, int N ) {
	for ( int i = 0; i < M; ++i ) {
		for ( int j = 0; j < N; ++j ) {
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	int M, N;
	std::cout << "Enter number of rows:";
	std::cin >> M;
	std::cout << "Enter number of cols:";
	std::cin >> N;
	int ** matrix = new int*[M];
	for ( int i =0; i < M; ++i ) {
		matrix[i] = new int[N];
	}
	std::cout << "Provide M x N matrix \n";
	for ( int i = 0; i < M; ++i ) {
		for ( int j = 0; j < N; ++j ) {
			std::cin >> matrix[i][j];
		}
	}

	std::cout << "Matrix Before:\n";
	print_Matrix(matrix, M, N);
	nullifyMatrix(matrix, M, N);
	std::cout << "Matrix After:\n";
	print_Matrix(matrix, M, N);
	return 0;
}
