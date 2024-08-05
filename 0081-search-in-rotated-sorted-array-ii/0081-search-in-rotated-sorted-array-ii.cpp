class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target)
                return true;
            //the follwoing condition is a barrier in determining the sorted half
            //so if such a condition arises, trim down the search space
            //as neither the nums[low] and nums[high] will be equal to target as they = nums[mid]
            //and we have already checked that the nums[mid] is not equal to the target
            else if(nums[low] == nums[mid] && nums[high] == nums[low]){
                low ++;
                high --;
                continue;
            }

            //if the left half is sorted
            else if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target < nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }

            //if right half is sorted
            else{
                if(target > nums[mid] && target <= nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};