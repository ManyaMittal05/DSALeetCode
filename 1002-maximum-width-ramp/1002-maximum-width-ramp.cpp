class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];
        int maxi = rightMax[n-1];

        for(int i = n-2; i >= 0; i--){
            maxi = max(maxi, nums[i]);
            rightMax[i] = maxi; 
        }

        int i = 0, j = 0;

        while(j < n){
            if(nums[i] <= rightMax[j]){
                ans = max(ans, j - i);
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return ans;
    }
};