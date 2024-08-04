#define MOD 1000000007;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subarrays;
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
                sum += nums[j];
                subarrays.push_back(sum);
            }
        }
        int ans = 0;
        sort(subarrays.begin(), subarrays.end());
        for(int i = left-1; i<right; i++){
            ans = (ans + subarrays[i]) % MOD;
        }
        return ans;
    }
};