class Solution {
public:
    bool checkMagicSquare(int i, int j, vector<vector<int>>& grid){
        int row1 = 0, row2 = 0, row3 = 0, col1 = 0, col2 = 0, col3 = 0, diag1 = 0, diag2 = 0;
        //5 should be the middle element in a magic square
        if(grid[i+1][j+1] != 5)
            return false;

        //sum of every row, column and diag of a magic square is 15

        //check if the numbers are distinct
        vector<int> hash(10, 1);

        for(int k = i; k<i+3; k++){
            for(int l = j; l<j+3; l++){
                if(grid[k][l] < 1 || grid[k][l] > 9)
                    return false;
                hash[grid[k][l]]--;
                if(hash[grid[k][l]] < 0)
                    return false;
            }
        }

        //for rows
        for(int k = j; k < j+3; k++){
            row1 += grid[i][k];
            row2 += grid[i+1][k];
            row3 += grid[i+2][k];
        }

        if(row1 != 15 || row2 != 15 || row3 != 15)
            return false;
        
        //for cols
        for(int k = i; k < i+3; k++){
            col1 += grid[k][j];
            col2 += grid[k][j+1];
            col3 += grid[k][j+2];
        }

        if(col1 != 15 || col2 != 15 || col3 != 15)
            return false;

        //for diagonals
        diag1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        diag2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];

        if(diag1 != 15 || diag1 != 15)
            return false;

        return true;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m < 3 || n < 3) return 0;
        int count = 0;
        for(int i = 0; i<= m-3; i++){
            for(int j = 0; j <= n-3; j++){
                //check if the matrix is magic sqaure
                count += checkMagicSquare(i, j, grid);
            }
        }
        return count;
    }
};