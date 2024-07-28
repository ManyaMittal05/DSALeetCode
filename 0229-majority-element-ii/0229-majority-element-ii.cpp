class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //at max there can be two elements in the nums whose frequency is > n/3
        //so initialise two counters and two elements for ans
        int n = nums.size();
        int count1 = 0, count2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;
        for(int i = 0; i<n; i++){
            if(count1  == 0 && ele2 != nums[i]){
                count1 = 1;
                ele1 = nums[i];
            }
            else if(count2 == 0 && ele1 != nums[i]){
                count2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1) count1++;
            else if(nums[i] == ele2) count2++;
            else{
                count1--;
                count2--;
            }
        }

        //validate if the ele1 and ele2 frequnecy is greater than n/3
        int maj = n/3;
        count1 = 0, count2 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == ele1) count1++;
            if(nums[i] == ele2) count2++;
        }
        vector<int> ans;
        if(count1 > maj) ans.push_back(ele1);
        if(count2 > maj) ans.push_back(ele2);
        return ans;
    }
};