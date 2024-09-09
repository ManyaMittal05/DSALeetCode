class Solution {
public:
    int countOddSubarrays(vector<int>& nums, int k){
        if(k < 0) return 0;
        int r = 0, l =0;
        int n = nums.size();
        int odd = 0;
        int count = 0;
        while(r < n){
            if(nums[r] % 2 != 0) odd++;

            while(odd > k){
                if(nums[l] % 2 != 0) odd--;
                l++;
            }
            count += r - l + 1;    
            r++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countOddSubarrays(nums, k) - countOddSubarrays(nums, k-1);
    }
};