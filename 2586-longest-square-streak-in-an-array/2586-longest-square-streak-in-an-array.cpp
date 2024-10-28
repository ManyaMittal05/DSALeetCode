class Solution {
public:

    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> set;
        set.insert(nums.begin(), nums.end());
        int maxLength = -1;
        for(int i = 0; i < nums.size(); i++){
            int ele = nums[i];
            int len = 1;
            while(true){
                long long newNum = (long long)ele * ele;
                if(newNum > INT_MAX) break;
                if(set.find(newNum) != set.end()){
                    len++;
                    ele = newNum;
                }
                else{
                    break;
                }
            }
            if(len > 1)
                maxLength = max(maxLength, len);
        }
        
        return maxLength;
    }
};