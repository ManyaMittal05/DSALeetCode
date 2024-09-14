class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = -1;
        int maxNumInd = -1;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > maxNum){
                maxNum = nums[i];
                maxNumInd = i;
            }
        }

        int len = 0, maxLen = 1;
        for(int i = maxNumInd; i<nums.size(); i++){
            if(nums[i] == maxNum) len++;
            else len = 0;
            maxLen = max(len, maxLen);
        }
        
        return maxLen;
    }
};