class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int k = 0;
        while(i < n && i <= j) {
            while(j < n && nums[j] == nums[i]){
                j++;
            }
            if(i < n-1 && j < n){
                nums[i+1] = nums[j];
                k++;
            }
            i++;
        }
        return k+1;
    }
};