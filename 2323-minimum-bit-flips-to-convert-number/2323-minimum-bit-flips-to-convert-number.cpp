class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xOr = start ^ goal;
        int count = 0;
        while(xOr != 0){
            if(xOr & 1 == 1){
                count++;
            }
            xOr = xOr >> 1;
        }
        return count;
    }
};