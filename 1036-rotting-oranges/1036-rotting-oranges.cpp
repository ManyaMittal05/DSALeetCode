class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        int rotten = 0, totalOranges = 0;
        int minutes = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> rottenMark(m, vector<bool> (n, false));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    totalOranges++;
                }
                else if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    rottenMark[i][j] = true;
                    totalOranges++;
                    rotten++;
                }
            }
        }

        while(!q.empty()){
            auto coord = q.front();
            q.pop();
            int i = coord.first.first;
            int j = coord.first.second;
            int time = coord.second;

            for(auto d : dir){
                int new_i = i + d[0];
                int new_j = j + d[1];

                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n){
                    if(!rottenMark[new_i][new_j] && grid[new_i][new_j] == 1){
                        q.push({{new_i, new_j}, time + 1});
                        rotten++;
                        rottenMark[new_i][new_j] = true;
                        minutes = max(minutes, time + 1);
                    }
                }
            }
        }

        if(rotten == totalOranges) return minutes;
        return -1;
    }
};