class Solution {
public:
    int findFloor(vector<int> nums, int target, int n){
        int low = 0, high = n-1;
        int floor = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] <= target){
                if(nums[mid] == target) floor = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return floor;
    }

    int findCeil(vector<int> nums, int target, int n){
        int low = 0, high = n-1;
        int ceil = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] >= target){
                if(nums[mid] == target) ceil = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ceil;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int floor = findFloor(nums, target, n);
        int ceil = findCeil(nums, target, n);
        return {ceil, floor};
    }
};