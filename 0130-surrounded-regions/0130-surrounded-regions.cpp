class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void dfs(vector<vector<char>> mat, int m, int n, int i, int j, vector<vector<bool>>& visited){
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || mat[i][j] == 'X')
            return;

        visited[i][j] = true;

        for(auto d : dir){
            int new_i = i + d[0];
            int new_j = j + d[1];

            dfs(mat, m, n , new_i, new_j, visited);
        }
    }

    void solve(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));

        //for vertical boundaries
        for(int i = 0; i < m; i++){
            if(!visited[i][0] && mat[i][0] == 'O'){
                dfs(mat, m, n, i, 0, visited);
            }
            if(!visited[i][n-1] && mat[i][n-1] == 'O'){
                dfs(mat, m, n, i, n-1, visited);
            }
        }

        //for horizontal boundaries
        for(int j = 0; j < n; j++){
            if(!visited[0][j] && mat[0][j] == 'O')
                dfs(mat, m, n, 0, j, visited);
            if(!visited[m-1][j] && mat[m-1][j] == 'O')
                dfs(mat, m, n, m - 1, j, visited);
        }


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j])
                    mat[i][j] = 'X';
            }
        }
    }
};