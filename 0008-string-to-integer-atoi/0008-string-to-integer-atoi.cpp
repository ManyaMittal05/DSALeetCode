class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(i < s.size() && s[i] == ' '){
            i++;
        }

        bool negative = false;
        if(i < s.size() && s[i] == '-'){
            negative = true;
            i++;
        }
        else if(i<s.size() && s[i] == '+'){
            i++;
        }

        long long num = 0;
        while(i < s.size() && (s[i] >= '0' && s[i] <= '9')){
            num = num*10 + (s[i] - '0');
            if(num > INT_MAX) return (negative) ? INT_MIN : INT_MAX;
            i++;
        }

        if(negative){
            return -num;
        }
        return num;
    }
};