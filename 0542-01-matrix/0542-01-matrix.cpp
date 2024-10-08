class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int, int>, int>> q; // coord, distance
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty()) {
            auto p = q.front();
            int i = p.first.first;
            int j = p.first.second;
            int dist = p.second;
            q.pop();

            for (auto d : dir) {
                int new_i = i + d[0];
                int new_j = j + d[1];

                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m &&
                    mat[new_i][new_j] == 1 && ans[new_i][new_j] == INT_MAX){
                        q.push({{new_i, new_j}, dist+1});
                        ans[new_i][new_j] = dist+1;
                    }
            }
        }
        return ans;
    }
};