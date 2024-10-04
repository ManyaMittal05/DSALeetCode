class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if(n == 2) return(skill[0] * skill[1]);
        long long sum = 0;

        vector<int> cnt(1001, 0);
        for(int x : skill){
            cnt[x]++;
            sum += x;
        }

        int numOfPairs = n/2;
        if(sum % numOfPairs != 0) return -1;
        int targetSum = sum / numOfPairs;

        long long chemistry = 0;
        for(int  i = 0; i<n; i++){
            int rem = targetSum - skill[i];
            if(cnt[rem] > 0){
                chemistry += skill[i] * rem;
                cnt[rem]--;
            }
            else return -1;
        }
        return chemistry / 2;
    }
};