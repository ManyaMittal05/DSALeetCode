class Solution {
public:
    void helper(string s, int i, unordered_set<string>& set, int currCount, int& maxCount){
        
        if(currCount + s.size() - i <= maxCount)
            return;

        if(i >= s.size()){
            maxCount = max(maxCount, currCount);
            return;
        }

        for(int j = i; j < s.size(); j++){
            string substring = s.substr(i, j - i + 1);
            if(set.find(substring) == set.end()){
                set.insert(substring);
                helper(s, j + 1, set, currCount + 1, maxCount);
                set.erase(substring);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        int currCount = 0, maxCount = 0;
        helper(s, 0, set, currCount, maxCount);
        return maxCount;
    }
};