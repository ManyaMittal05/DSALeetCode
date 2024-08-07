class Solution {
public:

    //since we need to simulateously rotten the oranges which are present int the neighbourhood
    //we will use the level wise order traversal i.e. bfs
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> directions = {{1,0}, {0,-1}, {0,1}, {-1,0}};
        queue<vector<int>> q;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                }
            }
        }
        int max_time = 0;
        while(!q.empty()){
            vector<int> values = q.front();
            q.pop();
            int i = values[0];
            int j = values[1];
            int time = values[2];
            for(auto d : directions){
                int new_i = i + d[0];
                int new_j = j + d[1];

                if(new_i >= 0 && new_i < m && new_j >=0 && new_j < n 
                        && grid[new_i][new_j] == 1){
                    grid[new_i][new_j] = 2;
                    q.push({new_i, new_j, time+1});
                    max_time = max(max_time, time+1);
                }
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return max_time;
    }
};