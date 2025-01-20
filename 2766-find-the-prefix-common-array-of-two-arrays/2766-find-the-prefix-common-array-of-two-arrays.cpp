class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n+1, 0);
        vector<int> ans;
        int dups = 0;
        for(int i = 0; i < n; i++){
            freq[A[i]]++;
            freq[B[i]]++;
            if(A[i] == B[i]) dups++;
            else{
                if(freq[A[i]] == 2) dups++;
                if(freq[B[i]] == 2) dups++;
            }

            ans.push_back(dups); 
        }
        return ans;
    }
};