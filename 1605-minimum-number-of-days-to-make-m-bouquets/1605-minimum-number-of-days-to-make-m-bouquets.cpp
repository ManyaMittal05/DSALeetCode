class Solution {
public:
    bool isPossible(vector<int> bloomDay, int m, int k, int mid){
        int count = 0, bouq = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                count++;
                if(count == k){
                    bouq++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }
        if(bouq >= m)
            return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long limit = (long long)m*(long long)k;
        int n = bloomDay.size();
        if(limit > n)
            return -1;
        
        int low = 0, high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(isPossible(bloomDay, m, k, mid)){
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