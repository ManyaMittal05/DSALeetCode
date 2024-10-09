class Solution {
public:

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            if (!visited[i][0] && grid[i][0] == 1){
                q.push({i, 0});
                visited[i][0] = true;
            }
            if (!visited[i][n - 1] && grid[i][n - 1] == 1){
                q.push({i, n - 1});
                visited[i][n-1] = true;
            }
        }

        for (int j = 0; j < n; j++) {
            if (!visited[0][j] && grid[0][j] == 1){
                q.push({0, j});
                visited[0][j] = true;
            }
            if (!visited[m - 1][j] && grid[m - 1][j] == 1){
                q.push({m - 1, j});
                visited[m-1][j] = true;
            }
        }

        while (!q.empty()) {
            auto p = q.front();
            int i = p.first;
            int j = p.second;
            q.pop();

            for (auto d : dir) {
                int new_i = i + d[0];
                int new_j = j + d[1];

                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                    !visited[new_i][new_j] && grid[new_i][new_j] == 1){
                        visited[new_i][new_j] = true;
                        q.push({new_i, new_j});
                    }
            }
        }

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j])
                    count++;
            }
        }

        return count;
    }
};