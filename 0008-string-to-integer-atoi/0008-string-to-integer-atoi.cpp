class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        while(i < n && s[i] == ' '){
            i++;
        }

        bool pos = true;
        if(i < n && s[i] == '-'){
            pos = false;
            i++;
        }
        else if(i < n && s[i] == '+'){
            i++;
        }

        long long num = 0;
        while(i < n && isdigit(s[i])){
            num = num*10 + (s[i] - '0');
            if( num > INT_MAX)
            {
                if(pos) return INT_MAX;
                return INT_MIN;
            }
            i++;
        }

        if(pos) return num;
        return -num;
    }
};