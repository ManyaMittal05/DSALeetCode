class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        
        for(int i = 0; i <= nums.size() - k; i++){
            int maxi = nums[i];
            for(int j = i; j < i + k - 1; j++){
                if(nums[j] + 1 == nums[j+1]){
                    maxi = nums[j+1];
                }
                else{
                    maxi = -1;
                    break;
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};