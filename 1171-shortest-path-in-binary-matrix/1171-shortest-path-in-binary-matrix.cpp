class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        int n = grid.size();

        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        
        queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        dist[0][0] = 1;

        q.push({{0, 0}, 1});

        while(!q.empty()){
            auto p = q.front();
            int i = p.first.first;
            int j = p.first.second;
            int cellDist = p.second;
            q.pop();

            for(auto& d : dir){
                int new_i = i + d[0];
                int new_j = j + d[1];

                if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < n){
                    if(grid[new_i][new_j] == 0){
                        if(dist[new_i][new_j] > cellDist + 1){
                            
                            dist[new_i][new_j] = cellDist + 1;
                            q.push({{new_i, new_j}, dist[new_i][new_j]});
                        }
                    }
                }
            }
        }

        if(dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};