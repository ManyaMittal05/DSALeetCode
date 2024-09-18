class Solution {
public:

    bool helper(vector<vector<int>>& grid, int i, int j, int m, int n, int health, vector<vector<vector<int>>>& dp){
        if(i == m-1 && j == n-1 && health - grid[i][j] >= 1) return true;
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == -1) return false;
        if(health < 1) return false;
        if(dp[i][j][health] != -1) return dp[i][j][health];

        int val = grid[i][j];
        grid[i][j] = -1;
        bool left = helper(grid, i, j-1, m, n, health - val, dp);
        bool right = helper(grid, i, j+1, m, n, health - val, dp);
        bool up = helper(grid, i-1, j, m, n, health - val, dp);
        bool down = helper(grid, i+1, j, m, n, health - val, dp);

        grid[i][j] = val;

        return dp[i][j][health] = (left || right || up || down);
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (health+1, -1)));
        return helper(grid, 0, 0, m, n, health, dp);
    }
};