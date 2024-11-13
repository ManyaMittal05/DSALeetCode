class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int lowerBound = lower - nums[i];
            int upperBound = upper - nums[i];
            int lowerIndx = lower_bound(nums.begin() + i + 1, nums.end(), lowerBound) - nums.begin();
            int upperIndx = upper_bound(nums.begin() + i + 1, nums.end(), upperBound) - nums.begin();
            int lowerPairs = lowerIndx - i - 1;
            int upperPairs = upperIndx - i - 1;
            ans += (upperPairs - lowerPairs);
        }
        return ans;
    }
};