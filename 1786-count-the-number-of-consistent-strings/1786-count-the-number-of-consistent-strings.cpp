class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> freq(26, 0);

        for(char ch : allowed){
            freq[ch - 'a']++;
        }

        int count = 0;

        for(string w : words){
            int flag = 1;
            for(char ch : w){
                if(freq[ch - 'a'] == 0){
                    flag = 0;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};