class Solution {
public:
    int helper(vector<vector<int>>& grid, int nrows, int ncols, int i, int j, vector<vector<int>>& dp){
        if(i < 0 || i >= nrows || j < 0 || j >= ncols) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int diagUp = 0, right = 0, diagDown = 0;
        if(i - 1 >= 0 && j + 1 < ncols && grid[i-1][j+1] > grid[i][j])
            diagUp = 1 + helper(grid, nrows, ncols, i - 1, j + 1, dp);
        if(j + 1 < ncols && grid[i][j+1] > grid[i][j])
            right = 1 + helper(grid, nrows, ncols, i, j + 1, dp);
        if(i + 1 < nrows && j + 1 < ncols && grid[i+1][j+1] > grid[i][j])
            diagDown = 1 + helper(grid, nrows, ncols, i + 1, j + 1, dp);
        
        return dp[i][j] = max(diagUp, max(right, diagDown));
    }

    int maxMoves(vector<vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = grid[0].size();
        int ans = INT_MIN;
        vector<vector<int>> dp(nrows, vector<int> (ncols, -1));
        for(int i = 0; i < nrows; i++){
            int newCount = helper(grid, nrows, ncols, i, 0, dp);
            ans = max(ans, newCount);
        }
        return ans;
    }
};