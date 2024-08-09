class Solution {
public:
    bool isPossible(vector<int>weights, int days, int cap){
        int wt = 0, dayCount = 1;
        for(int i = 0; i<weights.size(); i++){
            if(wt + weights[i] <= cap){
                wt += weights[i];
            }
            else{
                dayCount++;
                wt = weights[i];
            }
        }
        return dayCount <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(isPossible(weights, days, mid)){
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