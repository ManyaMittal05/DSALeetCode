class Solution {
public:

    void solve(string num, int target, int ind, vector<string>& ans, string arrangement, long resultSoFar, long prevNum){
        if(ind == num.length()){
            if(resultSoFar == target){
                ans.push_back(arrangement);
                return;
            }
        }
        string currStr;
        long currNum = 0;
        for(int j = ind; j<num.size(); j++){
            if(j > ind && num[ind] == '0') //skipping leading zeros
                return;
            currStr += num[j];
            currNum = currNum*10 + num[j] - '0';
            if(ind == 0){
                //pick first number without adding any operator
                solve(num, target, j+1, ans, arrangement + currStr, currNum, currNum);
            }
            else{
                solve(num, target, j+1, ans, arrangement + "+" + currStr, resultSoFar + currNum, currNum);
                solve(num, target, j+1, ans, arrangement + "-" + currStr, resultSoFar - currNum, -currNum);
                solve(num, target, j+1, ans, arrangement + "*" + currStr, resultSoFar - prevNum + prevNum * currNum, prevNum * currNum);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(num, target, 0, ans, "", 0, 0);
        return ans;
    }
};