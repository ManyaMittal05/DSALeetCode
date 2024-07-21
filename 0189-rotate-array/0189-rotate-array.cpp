class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        //reverse first n-k elements in the array
        for(int i = 0; i < (n-k)/2; i++){
            swap(nums[i] , nums[n- k - i - 1]);
        }

        //reverse last k elements
        int s = (n + n - k);
        for(int i = n - k; i<s/2; i++){
            swap(nums[i], nums[s-i-1]);
        }
        
        //reverse whole array
        for(int i = 0; i<n/2; i++){
            swap(nums[i], nums[n-i-1]);
        }
        
    }
};