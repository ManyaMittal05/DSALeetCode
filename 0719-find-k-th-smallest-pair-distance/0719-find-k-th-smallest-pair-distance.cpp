class Solution {
public:
    bool isKSmallPairsPossible(vector<int>& nums, int k, int mid){
        int r = 1, l = 0;
        int n = nums.size();
        int count = 0;
        while(r < n){ 
            while(nums[r] - nums[l] > mid){
                l++;
            }
            count += r - l;
            r++;
        }

        return (count >= k);
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n-1] - nums[0];
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;

            if(isKSmallPairsPossible(nums, k, mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};