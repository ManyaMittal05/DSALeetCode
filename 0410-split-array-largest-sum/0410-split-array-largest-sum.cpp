class Solution {
public:
    bool isPossible(vector<int> nums, int k, int sum){
        int subSum = 0;
        int noofsubarrays = 1;
        for(int i = 0; i<nums.size(); i++){
            if(subSum + nums[i] <= sum){
                subSum += nums[i];
            }
            else{
                noofsubarrays++;
                subSum = nums[i];
            }
        }
        return k >= noofsubarrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN, high = 0;
        for(auto ele : nums){
            low = max(low, ele);
            high += ele;
        }        
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(isPossible(nums, k, mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};