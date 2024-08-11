class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited){

        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] 
            || grid[i][j] == 0)
            return;

        visited[i][j] = true;
        for(auto& d : dir){
            int new_i = i + d[0];
            int new_j = j + d[1];
            dfs(new_i ,new_j, grid, visited);
        }
    }

    int countIslands(vector<vector<int>> grid){
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        int islands = 0;
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    dfs(i, j, grid, visited);
                    islands++;
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if(countIslands(grid) != 1) return 0;


        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    if(countIslands(grid) != 1) 
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};