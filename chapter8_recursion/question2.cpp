//optimized solution to robots in grid
//(r,c) matrix
// ill add unoptimized solution as different part 
#include <bits/stdc++.h>

class point {
    public:
    int row;
    int column;
    point (int r, int c) : row (r), column (c) {}
};

bool getPath(int** matrix, int currrow, int currcolumn, std::vector<point *> &path, std::unordered_set<point *> &duplicateVisits)
{
        //if out of bounds or curr position is off limits, return false
    if(currrow< 0 || currcolumn < 0 || matrix[currrow][currcolumn]==-1)
    {
            return false;
    }

    point* currpos = new point(currrow,currcolumn); 
        //If we have already visited this position, then return false
    if(duplicateVisits.find(currpos)!= duplicateVisits.end())
    {
        return false;
    }

    bool atOrigin = currrow == 0 && currcolumn ==0;
        //Everytime robot moves up or left and it is a valid position, add the point to result vector
    if(atOrigin|| getPath(matrix, currrow-1, currcolumn,path,duplicateVisits)
                        || getPath(matrix,currrow,currcolumn-1,path,duplicateVisits))
    {
        path.push_back(currpos);
        return true;
    }
        duplicateVisits.insert(currpos);
    return false;
}

std::vector <point *> getPath(int** matrix, int rows, int columns)
{
    std::vector<point *> path;
    std::unordered_set<point*> duplicateVisits;

    if(rows != 0 ||matrix != nullptr)
    {
                if (getPath(matrix, rows - 1, columns - 1, path, duplicateVisits)){
                    return path;
        }
    }
        //Return an empty vector indicating path does not exist
    return path;
}

int** createMatrix(int rows, int columns){
    //initialize number of rows
    int** matrix = new int*[rows];
    //in each row, add a new column array
    for (int i = 0; i < rows; ++i){
        matrix[i] = new int[columns];
    }
    //place values (1 indicates position is valid, -1 indicates it is invalid)
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < columns; ++j){
            matrix[i][j] = 1;
        }
    }
    return matrix;
    
}

int main() {
    
    //create a 5x7 matrix (5 rows and 7 columns)
    int** matrix = createMatrix(5, 7);
    //set specific points as off-limits
    matrix[1][3] = -1;
    matrix[2][5] = -1;
    matrix[3][2] = -1;
    matrix[0][1] = -1;
    
    
    std::vector<point*> path = getPath(matrix, 5, 7);
    if (path.size() == 0){
       std:: cerr << "Path does not exist!\n";
        
    }
    else {
        for (int i = 0; i < path.size(); ++i){
            std::cout << "[" << path[i]->row << "]" << "[" << path[i]->column << "]\n" ;
        }
        
    }

}