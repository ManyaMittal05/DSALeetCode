class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(vector<vector<int>>& newGrid, vector<vector<bool>>& visited, int i, int j){
        visited[i][j] = true;

        for(auto d : directions){
            int new_i = i + d[0];
            int new_j = j + d[1];

            if(new_i >= 0 && new_i < newGrid.size() && new_j >= 0 && new_j < newGrid[0].size()){
                if(!visited[new_i][new_j] && newGrid[new_i][new_j] == 0){
                    dfs(newGrid, visited, new_i, new_j);
                }
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> newGrid(n*3, vector<int> (n*3 , 0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '/'){
                    newGrid[i*3][j*3+2] = 1;
                    newGrid[i*3+1][j*3+1] = 1;
                    newGrid[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\'){
                    newGrid[i*3+2][j*3+2] = 1;
                    newGrid[i*3+1][j*3+1] = 1;
                    newGrid[i*3][j*3] = 1;
                }
            }
        }

        vector<vector<bool>> visited(n*3, vector<bool> (n*3, false));
        int regionsCount = 0;
        for(int i =0; i<n*3; i++){
            for(int j = 0; j<n*3; j++){
                if(newGrid[i][j] == 0 && !visited[i][j]){
                    regionsCount++;
                    dfs(newGrid, visited, i, j);
                }
            }
        }

        return regionsCount;
    }
};