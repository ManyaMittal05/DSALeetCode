class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xOr = 0;
        for(int bit : derived){
            xOr ^= bit;
        }

        if(xOr == 0) return true;
        return false;
    }
};