class Solution {
public:
//similar to surrounded region question
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0} , {-1,0}};

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        visited[i][j] = true;

        for(auto d : dir){
            int new_i = i + d[0];
            int new_j = j + d[1];

            if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size()){
                if(!visited[new_i][new_j] && grid[new_i][new_j] == 1){
                    dfs(new_i, new_j, grid, visited);
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        //mark all the land boundary cells and the cells connected to it as visited
        //after marking them visited we will count all the non visited land cells
        //and that will be our ans

        //checking the upper boundary row and lower boundary row
        for(int j = 0; j<n; j++){
            if(grid[0][j] == 1 && !visited[0][j]){
                dfs(0, j, grid, visited);
            }

            if(grid[m-1][j] == 1 && !visited[m-1][j]){
                dfs(m-1, j, grid, visited);
            }
        }

        //checing the left boundary column and right boundary column
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1 && !visited[i][0]){
                dfs(i, 0, grid, visited);
            }

            if(grid[i][n-1] == 1 && !visited[i][n-1]){
                dfs(i, n-1, grid, visited);
            }
        }

        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j])
                    count++;
            }
        }

        return count;
    }
};