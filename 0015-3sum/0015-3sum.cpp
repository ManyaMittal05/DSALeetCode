class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0; 
        vector<vector<int>> ans;
        while(i <= n - 3){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(nums[j] == nums[j-1] && j < k) j++;
                    while(nums[k] == nums[k+1] && j < k) k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
            i++;
            while(nums[i] == nums[i-1] && i<=n-3) i++;
        }
        return ans;
    }
};