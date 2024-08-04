class neighborSum {
    vector<vector<int>> grid;
public:
    neighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
    }
    
    int adjacentSum(int value) {
        int sum = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == value){
                    if(i > 0){
                        sum += grid[i-1][j];
                    }
                    if(i < grid.size()-1){
                        sum += grid[i+1][j];
                    }
                    if(j > 0){
                        sum += grid[i][j-1];
                    }
                    if(j < grid[0].size()-1){
                        sum += grid[i][j+1];
                    }
                }
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        int sum = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == value){
                    if(i - 1 >= 0 && j-1 >= 0){
                        sum += grid[i-1][j-1];
                    }
                    if(i+1 < grid.size() && j+1 < grid[0].size()){
                        sum += grid[i+1][j+1];
                    }
                    if(i-1 >= 0 && j+1 < grid[0].size()){
                        sum += grid[i-1][j+1];
                    }
                    if(i+1 < grid.size() && j-1 >= 0){
                        sum += grid[i+1][j-1];
                    }
                }
            }
        }
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */