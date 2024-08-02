class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int r = 0, l = 0;
        int n = nums.size();
        int count1 = 0;
        for(int i = 0; i< n; i++){
            if(nums[i] == 1)
                count1++;
        }

        int len = 0, swaps = INT_MAX;
        int current0 = 0;
        while(r < 2*n){
            len++;
            if(nums[r%n] == 0) current0++;

            if(len > count1){
                if(nums[l%n] == 0) current0--;
                l++; 
                len--;
            }

            if(len == count1)
                swaps = min(swaps, current0);
            r++;
        }
        return swaps;
    }
};