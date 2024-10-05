class Solution {
public:

    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length()) return false;
        
        vector<int> mp1(26, 0);
        for(char ch : s1){
            mp1[ch - 'a']++;
        }

        vector<int> mp2(26, 0);
        int windowSize = s1.length();

        for(int i = 0; i<windowSize; i++){
            mp2[s2[i] - 'a']++;
        }

        if(mp1 == mp2) return true;
        for(int i = windowSize; i<s2.length(); i++){
            mp2[s2[i] - 'a']++;

            int oldIndex = s2[i - windowSize] - 'a';
            mp2[oldIndex]--;

            if(mp1 == mp2)
                return true;
        }
        return false;

        
    }
};