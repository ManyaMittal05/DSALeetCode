class Solution {
public:
    int findComplement(int num) {
        
        string newNum = "";
        while(num > 0){
            int rem = num % 2;
            num = num / 2;
            if(rem == 1) newNum += '0';
            else newNum += '1';
        }
        
        int ans = 0;
        for(int i = 0; i<newNum.length(); i++){
            if(newNum[i] == '1'){
                ans += pow(2, i);
            }
        }

        return ans;
    }
};