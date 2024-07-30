class Solution {
public:
    //4 cases:
    //1) all positive
    //2) even negatives
    //3) odd negatives
    //4) contains 0
    //in first two cases max prod will be prod of whole array
    //in third case we need to find one negative whose suffix or prefix has the max prod
    //when a zero is there, either its suffix or prefix contains the max prod
    //find prod from both ends
    //re-initialize the prod to 1 if zero is encountered
    //store max prod in a variable and return
    int maxProduct(vector<int>& nums) {
        double pref = 1;
        double suff = 1;
        double maxProd = INT_MIN;
        int n=nums.size();
        for(int i=0; i<n; i++){
            pref *= nums[i];
            suff *= nums[n-i-1];
            maxProd = max(maxProd, max(pref, suff));
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;
        }
        return maxProd;
    }
};