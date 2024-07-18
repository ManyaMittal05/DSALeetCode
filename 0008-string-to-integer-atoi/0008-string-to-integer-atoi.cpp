class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(i < s.size() && s[i] == ' '){
            i++;
        }

        int sign = 1;
        if(i < s.size() && s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(i<s.size() && s[i] == '+'){
            i++;
        }

        long long num = 0;
        while(i < s.size() && isdigit(s[i])){
            num = num*10 + (s[i] - '0');
            if(num > INT_MAX) return (sign == -1) ? INT_MIN : INT_MAX;
            i++;
        }

        return num*sign;
    }
};