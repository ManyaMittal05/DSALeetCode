class Solution {
public:
    int shelfWidth, n;
    int dp[1000]; // dp[i] height for book i

    int f(int i, vector<vector<int>>& books) {
        if (i<0) return 0; // Base case: no more books to place
        if (dp[i]!= -1) return dp[i]; 
        int layerH=0, Width_rem=shelfWidth, ans=INT_MAX;
        for(int j=i; j>=0; j--){
            Width_rem-=books[j][0];
            if (Width_rem<0) break;
            layerH=max(layerH, books[j][1]);
            ans=min(ans, layerH+f(j-1, books));
        }
        return dp[i]=ans;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        this->shelfWidth=shelfWidth;
        n=books.size();
        memset(dp, -1, sizeof(dp)); 
        return f(n-1, books); // Start from the last book
    }
};
