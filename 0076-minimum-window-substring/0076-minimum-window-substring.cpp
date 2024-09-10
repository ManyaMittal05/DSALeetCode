class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        int count = 0;
        int l = 0, r =0;
        int n = s.size();
        vector<int> freq(256, 0);
        int minLen = 1e9+7;
        int startIndex = -1;
        string result = "";

        for(auto c : t){
            freq[c]++;
        }

        while(r < n){

            if(freq[s[r]] > 0){
                count++;
            }
            freq[s[r]]--;

            while(count == t.size() && l < n){
                int len = r - l + 1;
                if(len < minLen){
                    minLen = len;
                    startIndex = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) count--;
                l++;
            }
            r++;
        }

        if(startIndex == -1) return "";

        for(int i = startIndex; i<startIndex + minLen; i++){
            result += s[i];
        }
        return result;

    }
};