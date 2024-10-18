class Solution {
public:
//maximum OR of an array is thge OR of all the elements of that array
    void helper(vector<int>& nums, int i, int targetOR, int& count, int calcOR){
        if(i == nums.size()){
            if(targetOR == calcOR)
                count++;
            return;
        }

        helper(nums, i + 1, targetOR, count, calcOR);

        calcOR = calcOR | nums[i];
        helper(nums, i + 1, targetOR, count, calcOR);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int targetOR = 0;
        for(auto num : nums)
            targetOR = targetOR | num;

        int count = 0;
        helper(nums, 0, targetOR, count, 0);
        return count;
    }
};