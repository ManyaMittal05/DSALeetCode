class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> xOr(n);

        xOr[0] = arr[0];
        for(int i = 1; i<n; i++){
            xOr[i] = xOr[i-1] ^ arr[i];
        }

        vector<int> ans;
        for(auto q : queries){
            if(q[0] == 0) ans.push_back(xOr[q[1]]);
            else{
                int result = xOr[q[0]-1] ^ xOr[q[1]];
                ans.push_back(result);
            }
        }
        return ans;
    }
};