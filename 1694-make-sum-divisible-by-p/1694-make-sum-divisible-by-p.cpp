class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }

        int rem = sum % p;
        if(rem == 0) return 0;

        long long prefixSum = 0;
        unordered_map<int, int> prefixMod;
        prefixMod[0] = -1;
        int minLen = n;

        for(int i = 0; i<n; i++){
            prefixSum += nums[i];
            int currMod = prefixSum % p;
            int targetMod = (currMod - rem + p) % p;

            if(prefixMod.find(targetMod) != prefixMod.end()){
                minLen = min(minLen, i - prefixMod[targetMod]);
            }
            prefixMod[currMod] = i;
        }

        if(minLen >= n) return -1;
        return minLen;

        
    }
};