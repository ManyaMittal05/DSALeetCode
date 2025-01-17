class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int count1 = 0, count0 = 0;
        for(int bit : derived){
            if(bit == 0) count0++;
            else count1++;
        }

        if(count1 % 2 == 0) return true;
        return false;
    }
};