class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find the first index whose value is greater than its next index value
        int n = nums.size();
        int index = -1;
        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        } 

        if(index == -1){ //the array is in decreasing order so next permuation is array in increasing order
            reverse(nums.begin(), nums.end());
            return;
        }   

        //swap the value of index found above with the first index having value smaller than the index's value
        for(int i = n-1; i >= index; i--){
            if(nums[index] < nums[i]){
                swap(nums[i], nums[index]);
                break;
            }
        } 

        reverse(nums.begin() + index + 1, nums.end());
    }
};