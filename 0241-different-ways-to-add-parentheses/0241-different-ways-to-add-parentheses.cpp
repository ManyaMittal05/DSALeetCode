class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> ans;

        unordered_map<string, vector<int>> dp;

        for(int ind = 0; ind < exp.size(); ind++){
            char curr = exp[ind];
            if(curr == '+' || curr == '-' || curr == '*'){

                vector<int> left, right;

                string str1 = exp.substr(0, ind);
                string str2 = exp.substr(ind+1);

                if(dp.find(str1) != dp.end()) return dp[str1];
                else left = diffWaysToCompute(str1);

                if(dp.find(str2) != dp.end()) return dp[str2];
                else right = diffWaysToCompute(str2);

                for(auto i : left){
                    for(auto j : right){
                        switch(curr){
                            case '+' : ans.push_back(i+j); break;
                            case '-' : ans.push_back(i-j); break;
                            case '*' : ans.push_back(i*j); break;
                        }
                    }
                }
            }
        }

        if(ans.empty()) ans.push_back(stoi(exp));
        return dp[exp] = ans;

    }
};