class Solution {
public:
    int numSubarrayWithSumLessThanOrEqual(vector<int>& nums, int goal){
        if(goal < 0 ) return 0;
        int r = 0, l = 0; 
        int n = nums.size();
        int count = 0;
        int sum = 0;

        while(r < n){
            sum += nums[r];
            
            while(l < n && sum > goal){
                sum -= nums[l];
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarrayWithSumLessThanOrEqual(nums, goal) -
                numSubarrayWithSumLessThanOrEqual(nums, goal - 1);
    }
};