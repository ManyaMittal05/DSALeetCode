class Solution {
public:
//similar to surrounded region question
//doing by bfs
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0} , {-1,0}};

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        queue<pair<int,int>> q;

        //mark all the land boundary cells and the cells connected to it as visited
        //after marking them visited we will count all the non visited land cells
        //and that will be our ans

        //checking the upper boundary row and lower boundary row
        for(int j = 0; j<n; j++){
            if(grid[0][j] == 1){
                q.push({0,j});
                visited[0][j] = true;
            }

            if(grid[m-1][j] == 1){
                q.push({m-1, j});
                visited[m-1][j] = true;
            }
        }

        //checing the left boundary column and right boundary column
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1){
                q.push({i, 0});
                visited[i][0] = true;
            }

            if(grid[i][n-1] == 1){
                q.push({i, n-1});
                visited[i][n-1] = true;
            }
        }

        while(!q.empty()){
            pair<int,int> coord = q.front();
            int i = coord.first;
            int j = coord.second;
            q.pop();

            for(auto d : dir){
                int new_i = i + d[0];
                int new_j = j + d[1];

                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n ){
                    if(grid[new_i][new_j] == 1 && !visited[new_i][new_j]){
                        visited[new_i][new_j] = true;
                        q.push({new_i, new_j});
                    }
                }
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