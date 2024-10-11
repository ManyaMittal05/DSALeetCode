class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();

        //first pass - stroing the smaller elements
        for(int i = 0; i<n; i++){
            if(st.empty() || nums[i] < nums[st.top()]){
                st.push(i);
            }
        }

        //second pass - finding the ans
        int ans = 0;
        for(int i = n-1; i >= 0; i--){
            if(st.empty()) break;
            while(!st.empty() && nums[i] >= nums[st.top()]){
                ans = max(ans, i - st.top());
                st.pop();
            }
        }
        return ans;
    }
};