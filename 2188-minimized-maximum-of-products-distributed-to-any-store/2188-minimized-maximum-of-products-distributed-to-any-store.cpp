class Solution {
public:
    bool canDistribute(int n, vector<int>& quantities, int x){
        int total = 0;
        if(x == 0) return false;
        for(int i = 0; i < quantities.size(); i++){
            total += ceil((double)quantities[i] / (double) x);
        }
        return total <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 0;
        int high = *max_element(quantities.begin(), quantities.end());
        if(n == quantities.size()){
            return high;
        }
        int ans = 0;

        while(low <= high){
            int mid = (low + high) / 2;
            if(canDistribute(n, quantities, mid)){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;

    }
};