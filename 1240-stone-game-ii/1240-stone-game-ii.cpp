class Solution {
public:
    //memoization
    int solve(vector<int>& piles, int n, int i, int m, int person, vector<vector<vector<int>>>& dp){
        if(i >= n)
            return 0;

        if(dp[person][i][m] != -1) return dp[person][i][m];
        int stones = 0;
        int result;
        if(person == 1) result = INT_MIN; //because we need to take max result when its alice's turn
        else result = INT_MAX;//beacuse we need to take min result when its bob's turn

        int max_x = min(2*m, n - i);

        for(int x = 1; x <= max_x; x++){
            stones += piles[i + x - 1];

            //when its your turn, do your best
            if(person == 1){ //Alice's turn
                result = max(result, stones + solve(piles, n, i+x, max(m, x), 0, dp));
            }
            //when its opponent's turn, expect the worst
            else{//Bob's turn
                result = min(result, solve(piles, n, i+x, max(m, x), 1, dp));
            }
        }
        
        return dp[person][i][m] = result;
    }
    int stoneGameII(vector<int>& piles) {
        int i = 0;
        int n = piles.size();
        int m = 1;
        int person = 1; //person = 1 means Alice and person = 2 means Bob
        vector<vector<vector<int>>> dp(2, vector<vector<int>> (n+1, vector<int> (n+1, -1)));
        return solve(piles, n, i, m, person, dp);
    }
};