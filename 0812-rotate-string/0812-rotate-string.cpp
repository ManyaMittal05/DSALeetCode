class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        for(int i = 0; i<s.size(); i++){
            char c = s.back();
            s.pop_back();
            s = c + s;
            if(s == goal) return true;
        }
        return false;
    }
};