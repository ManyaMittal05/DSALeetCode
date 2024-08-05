class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        int low = 0, high = n-1;
        if(n == 1 || nums[0] < nums[n-1]) 
            return nums[0];
        
        if(nums[n-1] < nums[0] && nums[n-1] < nums[n-2]){
            return nums[n-1];
        }

        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1])
                return nums[mid];
            //if left half is sorted
            else if(nums[low] <= nums[mid]){
                if(nums[high] >= nums[mid]){
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};