class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        
        int sumSingle = 0, sumDouble = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] < 10){
                sumSingle += nums[i];
            }
            else{
                sumDouble += nums[i];
            }
        }
        
        if(sumSingle == sumDouble) return false;
        return true;
        
    }
};