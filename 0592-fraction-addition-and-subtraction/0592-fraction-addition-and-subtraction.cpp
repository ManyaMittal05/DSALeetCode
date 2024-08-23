class Solution {
public:
    string reduceFraction(string frac){
        int i = 0;
        string num = "", den = "";

        while(frac[i] != '/'){
            num += frac[i];
            i++;
        }

        while(i < frac.length()){
            if(frac[i] == '/'){
                i++;
                continue;
            }
            den += frac[i];
            i++;
        }

        int numerator = stoi(num), denominator = stoi(den);
        if(numerator == 0) return "0/1";

        int range = abs(denominator);
        if (abs(numerator) < abs(denominator)) range = abs(numerator);

        for(int j = range; j>=2; j--){
            if(numerator % j == 0 && denominator % j == 0){
                numerator /= j;
                denominator /= j;
            }
        }

        num = to_string(numerator);
        den = to_string(denominator);

        return (num + "/" + den);
    }
    string fractionAddition(string expression) {
        if(isdigit(expression[0])){
            expression = "+" + expression;
        }
        stack<string> st;
        
        int i = 0;
        while( i < expression.size()){
            string val = "";
            if(expression[i] == '-' || expression[i] == '+'){
                val += expression[i];
                i++;
                while(i < expression.size() && expression[i] != '+' && expression[i] != '-'){
                    val += expression[i];
                    i++;
                }
                st.push(val);
            }
        }

        while(st.size() != 1){
            string frac1 = st.top();
            st.pop();
            string frac2 = st.top();
            st.pop();
            int i = 0, j = 0;

            string num1 = "", den1 = "", num2 = "", den2 = "";
            while(frac1[i] != '/'){
                num1 += frac1[i];
                i++;
            }

            while(i < frac1.length()){
                if(frac1[i] == '/') {
                    i++;
                    continue;
                }
                den1 += frac1[i];
                i++;
            }

            while(frac2[j] != '/'){
                num2 += frac2[j];
                j++;
            }

            while(j < frac2.length()){
                if(frac2[j] == '/'){
                    j++;
                    continue;
                }
                den2 += frac2[j];
                j++;
            }

            int n1 = stoi(num1), n2 = stoi(num2), d1 = stoi(den1), d2 = stoi(den2);

            int ansNum = (n1*d2) + (n2*d1);
            int ansDen = (d1*d2);
            string final = to_string(ansNum) + "/" + to_string(ansDen);
            st.push(final);
        }

        return reduceFraction(st.top());
    }
};