class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = prices[0];
        for(int i = 1; i<prices.size(); i++){
            if(prices[i] < prices[i-1]){
                mini = min(mini, prices[i]);
            }
            else{
                if(prices[i] > mini){
                    profit = max(profit, prices[i] - mini);
                }
            }
        }
        return profit;
    }
};