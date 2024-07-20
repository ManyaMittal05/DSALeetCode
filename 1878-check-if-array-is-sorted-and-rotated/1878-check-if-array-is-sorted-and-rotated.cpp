class Solution {
public:
    bool check(vector<int>& nums) {
        int checkCount = 0;
        int n = nums.size();
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1])
                checkCount ++;
        }

        if(checkCount == 1 && nums[0] < nums[n-1]) return false;
        return (checkCount <= 1);
    }
};