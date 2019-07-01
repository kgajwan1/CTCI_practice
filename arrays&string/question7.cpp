//1.7Rotate a matrix by 90' clockwise ( or anticlockwise).
//[1,2,3]
//[2,3,4]
//[3,4,5]
//after

#include <bits/stdc++.h>

void rotate( int ** matrix, int N ) {
	for( int i = 0; i < N/2; ++i ) {
		for( int j = i; j < N-i-1; ++j ) {
			
				int temp = matrix[i][j];
				//std::cout << temp<<'\n';
				//swapper code
				matrix[i][j] = matrix[j][N-i-1];
				matrix[j][N-i-1] = matrix[N-i-1][N-j-1];
				matrix[N-i-1][N-j-1]= matrix[N-j-1][i];
				matrix[N-j-1][i] = temp;
		}
	}
}

void printMatrix( int ** matrix, int N) {
	for ( int i = 0; i < N; ++i ) {
		for( int j = 0; j < N; ++j ) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
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
	printMatrix(matrix, N);

	std::cout << "Rotated matrix  by 90(anticlockwise):\n";
	rotate(matrix, N);
	printMatrix(matrix, N);
	return 0;
}
