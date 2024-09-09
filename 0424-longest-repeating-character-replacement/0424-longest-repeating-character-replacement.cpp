class Solution {
public:
    int characterReplacement(string s, int k) {
        int r = 0, l = 0; 
        int n = s.size();
        int maxLen = 0;
        unordered_map<char, int> freq;
        int maxFreq = 0;

        while( r < n){
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);
            int len = r - l + 1;

            if(len - maxFreq > k){
                freq[s[l]]--;
                l++;
            }
            else{
                maxLen = max(maxLen, len);
            }
            r++;
        }
        return maxLen;
    }
};