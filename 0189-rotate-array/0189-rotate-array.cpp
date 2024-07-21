class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        //reverse first n-k elements in the array
        reverse(nums.begin(), nums.end() - k);

        //reverse last k elements
        reverse(nums.end() - k, nums.end());
        
        //reverse whole array
        reverse(nums.begin(), nums.end());
        
    }
};