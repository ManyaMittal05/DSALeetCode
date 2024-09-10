class Solution {
public:
    int subarraysWithAtmostKDistinct(vector<int> nums, int k){
        if(k <= 0)return 0;
        int n = nums.size();
        int l = 0, r = 0;
        int count = 0;
        unordered_map<int,int> freq;
        while(r < n){
            freq[nums[r]]++;
            while(freq.size() > k){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) freq.erase(nums[l]);
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtmostKDistinct(nums, k) - subarraysWithAtmostKDistinct(nums,k-1);
    }
};