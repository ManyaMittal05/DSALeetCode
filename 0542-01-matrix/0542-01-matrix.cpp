class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> directions = {{1,0}, {0,-1}, {0,1}, {-1,0}};
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int> (n, 0));
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        queue<vector<int>> q;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            vector<int> ele = q.front();
            q.pop();
            int i = ele[0];
            int j = ele[1];
            int steps = ele[2];

            dist[i][j] = steps;
            for(auto d : directions){
                int new_i = i + d[0];
                int new_j = j + d[1];

                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n
                    && !visited[new_i][new_j]){
                        q.push({new_i, new_j, steps+1});
                        visited[new_i][new_j] = true;
                }
            }
        }
        return dist;
    }
};