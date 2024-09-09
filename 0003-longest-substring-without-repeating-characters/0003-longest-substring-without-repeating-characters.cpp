class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int right = 0, left = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        int len = 0;
        while(right < n){
            mp[s[right]]++;

            while(left < n && mp[s[right]] > 1){
                mp[s[left]]--;
                left++;
            }

            len = max(len, right - left + 1);
            right++;
        }

        return len;
    }
};