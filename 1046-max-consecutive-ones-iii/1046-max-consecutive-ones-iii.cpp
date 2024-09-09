class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r = 0, l = 0;
        int countZeros = 0;
        int n = nums.size();
        int len = 0;

        while(r < n){
            if(nums[r] == 0) countZeros++;

            if(l < n && countZeros > k){
                if(nums[l] == 0) countZeros--;
                l++;
            }
            else
                len = max(len , r - l + 1);
            r++;
        }

        return len;
    }
};