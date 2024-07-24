class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> prefix_sum;

        int sum = 0, count = 0;
        prefix_sum[0] = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            if(sum == k) count ++;
            int rem = sum - k;
            if(prefix_sum.find(rem) != prefix_sum.end()){
                count += prefix_sum[rem];
            }
            prefix_sum[sum]++;
        }
        return count;
    }
};