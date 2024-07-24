class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto ele : nums){
            set.insert(ele);
        }
        int len = 0;
        for(int i = 0; i<nums.size(); i++){
            if(set.find(nums[i] - 1) == set.end()){
                int currEle = nums[i];
                int count  = 1;
                while(set.find(currEle + 1) != set.end()){
                    currEle++;
                    count++;
                }
                len = max(len, count);
            }
        }
        return len;
    }
};