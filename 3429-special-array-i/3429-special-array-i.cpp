class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1) return true;
        for(int i = 1; i < nums.size(); i++){
            int check = nums[i] ^ nums[i-1];
            if((check & 1) == 0)
                return false;
        }
        return true;
    }
};