class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans = isWater;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 0)
                    ans[i][j] = -1;
                else {
                    ans[i][j] = 0;
                    visited[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }

        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            auto p = q.front();
            int i = p.first.first;
            int j = p.first.second;
            int val = p.second;
            q.pop();

            for (auto d : dir) {
                int new_i = i + d[0];
                int new_j = j + d[1];
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                    !visited[new_i][new_j]) {
                        visited[new_i][new_j] = true;
                        ans[new_i][new_j] = val + 1;
                        q.push({{new_i, new_j}, val + 1});
                }
            }
        }

        return ans;
    }
};