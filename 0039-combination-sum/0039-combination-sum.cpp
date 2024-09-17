class Solution {
public:
    void find(int ind,int target,vector<int>&candidates,vector<vector<int>>&ans,vector<int>&ds){
        if(ind>=candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return ;
        }
        find(ind+1,target,candidates,ans,ds);

        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            find(ind,target-candidates[ind],candidates,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        find(0,target,candidates,ans,ds);
        return ans;
    }
};