class Solution {
public:
    long long countHours(vector<int>& piles, int k){
        long long count = 0;
        for(int i = 0; i<piles.size(); i++){
            count += ceil((double)piles[i] / (double)k);
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            long long hours = countHours(piles, mid);

            if(hours <= h){
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