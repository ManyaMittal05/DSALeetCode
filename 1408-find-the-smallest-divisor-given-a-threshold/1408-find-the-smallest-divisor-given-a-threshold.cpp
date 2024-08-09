class Solution {
public:
    bool isPossible(vector<int> nums, int threshold, int div){
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += ceil((double)nums[i] / (double)div);
        }
        
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            
            if(isPossible(nums, threshold, mid)){
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