class Solution {
public:
//memoization

    int solve(vector<vector<int>>& books, int ind, int remainingWidth, int maxHt,
                vector<vector<int>>& dp, int shelfWidth){
        if(ind < 0) return maxHt;
        
        if(dp[ind][remainingWidth] != -1) return dp[ind][remainingWidth];
        int bookW = books[ind][0];
        int bookHt = books[ind][1];

        int keep = INT_MAX, skip = INT_MAX;

        if(bookW <= remainingWidth){
            keep = solve(books, ind-1, remainingWidth - bookW, max(maxHt, bookHt), dp, shelfWidth);
        }
        
        skip = maxHt + solve(books, ind-1, shelfWidth - bookW, bookHt, dp, shelfWidth);
    
        return dp[ind][remainingWidth] = min(keep, skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(n, vector<int> (shelfWidth+1, -1));
        return solve(books, n-1, shelfWidth, 0, dp, shelfWidth);
        
    }
};