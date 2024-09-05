class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
       int m = rolls.size();
       int sum_m = accumulate(rolls.begin(), rolls.end(), 0);
       int sum_n = mean * (n + m) - sum_m; 

       if(sum_n <= 0 || sum_n > 6 * n) return {};

       int ele = sum_n / n;
       if(ele > 6 || ele < 1) return {};
       vector<int> ans(n, ele);
       sum_n -= ele * n;
       int i = 0;
       while(sum_n > 0){
            if(ans[i] + 1 <= 6) ans[i]++;
            i++;
            sum_n--;
       }

       return ans;
    }
};