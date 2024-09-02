class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0; 
        for(auto c : chalk){
            sum += c;
        }

        while(k - sum >= 0){
            k -= sum;
        }
        for(int i = 0; i<chalk.size(); i++){
            if(k - chalk[i] < 0) return i;
            k -= chalk[i];
        }
        return -1;
    }
};