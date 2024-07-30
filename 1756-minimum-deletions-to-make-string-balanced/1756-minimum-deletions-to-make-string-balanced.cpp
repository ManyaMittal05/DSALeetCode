class Solution {
public:
    int minimumDeletions(string s) {
        int maxDel = 0;
        int countABefore = 0, countBAfter = 0;
        int n = s.size();
        vector<int> prefixSumOfA(n,0);
        for(int i = 0; i<n; i++){
            if(s[i] == 'a')
                countABefore++;
            prefixSumOfA[i] = countABefore;
        }
        for(int i = n-1; i>=0; i--){
            if(s[i] == 'b')
                countBAfter++;
            maxDel = max(maxDel, prefixSumOfA[i] + countBAfter);
        }
        maxDel = n - maxDel;
        return maxDel;
    }
};