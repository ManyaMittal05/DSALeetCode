class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& board){
        visited[i][j] = true;

        for(auto& d : directions){
            int new_i = i + d[0];
            int new_j = j + d[1];
            
            if(new_i >= 0 && new_i < board.size() && new_j >= 0 && new_j < board[0].size()){
                if(board[new_i][new_j] == 'O' && !visited[new_i][new_j])
                    dfs(new_i, new_j, visited, board);
            }
            
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                //check boundary cases
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    if(board[i][j] == 'O' && !visited[i][j]){
                        dfs(i, j, visited, board);
                    }
                }
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(visited[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }
};