class Solution {
public:
vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void dfs(vector<vector<int>>& mat, int m, int n, int i, int j, vector<vector<bool>>& visited){
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || mat[i][j] == 0)
            return;

        visited[i][j] = true;
        mat[i][j] = 0;

        for(auto d : dir){
            int new_i = i + d[0];
            int new_j = j + d[1];

            dfs(mat, m, n , new_i, new_j, visited);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n , false));

        for(int i = 0; i < m; i++){
            if(!visited[i][0] && grid[i][0] == 1)
                dfs(grid, m, n, i, 0, visited);
            if(!visited[i][n-1] && grid[i][n-1] == 1)
                dfs(grid, m, n, i , n-1, visited);
        }

        for(int j = 0; j < n; j++){
            if(!visited[0][j] && grid[0][j] == 1)
                dfs(grid, m, n, 0, j, visited);
            if(!visited[m-1][j] && grid[m-1][j] == 1)
                dfs(grid, m, n, m-1, j, visited);
        }

        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};