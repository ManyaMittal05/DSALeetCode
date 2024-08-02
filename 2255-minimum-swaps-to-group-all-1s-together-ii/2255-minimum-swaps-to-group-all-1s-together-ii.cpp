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
        for(int i = 0; i<n-1; i++){
            nums.push_back(nums[i]);
        }

        int len = 0, swaps = INT_MAX;
        int count = 0;
        while(r < 2*n-1){
            len++;
            if(nums[r] != 1) count++;

            if(len > count1){
                if(nums[l] == 0) count--;
                l++; 
                len--;
            }

            if(len == count1)
                swaps = min(swaps, count);
            r++;
        }
        return swaps;
    }
};