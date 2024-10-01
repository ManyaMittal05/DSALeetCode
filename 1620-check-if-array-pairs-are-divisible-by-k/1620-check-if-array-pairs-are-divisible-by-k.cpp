class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int rem = (arr[i] % k + k) % k; //adding k to include negative cases
            freq[rem]++;
        }

        if(freq[0] % 2 != 0) return false;
        if(k % 2 == 0 && freq[k/2] % 2 != 0) return false;

        for(int i = 1; i<=(k-1)/2; i++){
            if(freq[i] != freq[k-i])
                return false;
        }
        return true;
    }
};