class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int count = 0;
        for(int bit : derived){
            count += bit;
        }

        if(count % 2 == 0) return true;
        return false;
    }
};