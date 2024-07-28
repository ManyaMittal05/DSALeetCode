class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        vector<vector<int>> ans;
        while(i <= n - 4){
            int j = i + 1;
            while(j <= n - 3){
                int k = j+1;
                int l = n-1;
                
                while(k < l){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while(nums[k] == nums[k-1] && k < l) k++;
                        while(nums[l] == nums[l+1] && k < l) l--;
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
                j++;
                while(nums[j] == nums[j-1] && j <= n-3) j++;
            }
            i++;
            while(nums[i] == nums[i-1] && i <= n-4) i++;
        }
        return ans;
    }
};