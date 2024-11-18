class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            int sum = 0;
            if(k > 0){
                for(int j = i+1; j < i + k + 1; j++){
                    sum += code[j % n];
                }
            }
            else{
                for(int j = i-1; j >= i + k; j--){ //since k < 0, i + k = i - abs(k)
                    int ind = (j % n + n) % n;
                    sum += code[ind];
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
};