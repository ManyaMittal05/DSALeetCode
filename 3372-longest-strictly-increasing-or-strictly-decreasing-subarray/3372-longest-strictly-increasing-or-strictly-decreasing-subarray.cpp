class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int incLen = 1, decLen = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                incLen++;
                decLen = 1;
                ans = max(ans, incLen);
            }
            else if(nums[i] < nums[i-1]){
                decLen++;
                incLen = 1;
                ans = max(ans, decLen);
            }
            else{
                incLen = 1;
                decLen = 1;
            }
        }
        return ans;
    }
};