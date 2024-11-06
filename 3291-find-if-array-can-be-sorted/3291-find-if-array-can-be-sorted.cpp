class Solution {
public:
    int countSetBits(int num){
        int count = 0;
        while(num != 0){
            if((num & 1) == 1) count++;
            num = num >> 1;
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n-i-1; j++){
                if(nums[j] > nums[j+1]){
                    if(countSetBits(nums[j]) != countSetBits(nums[j+1]))
                        return false;
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        return true;
    }
};