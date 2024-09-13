class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> xOr(n);

        xOr[0] = arr[0];
        for(int i = 1; i<n; i++){
            xOr[i] = xOr[i-1] ^ arr[i];
        }

        vector<int> ans(queries.size());
        int i = 0;
        for(auto q : queries){
            if(q[0] == 0) ans[i++] = xOr[q[1]];
            else{
                int result = xOr[q[0]-1] ^ xOr[q[1]];
                ans[i++] = result;
            }
        }
        return ans;
    }
};