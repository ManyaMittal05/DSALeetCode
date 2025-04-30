class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0; 
        for(int i = 0; i < nums.size(); i++){
            int numDigits = 0;
            int n = nums[i];
            while(n > 0){
                numDigits++;
                n /= 10;
            }
            if(numDigits % 2 == 0)
                count++;
        }
        return count;
    }
};