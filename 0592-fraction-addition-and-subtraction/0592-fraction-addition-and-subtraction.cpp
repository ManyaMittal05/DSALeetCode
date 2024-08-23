class Solution {
public:
    pair<int ,int> reduceFraction(int numerator, int denominator){

        if(numerator == 0) return {0,1};

        int range = abs(denominator);
        if (abs(numerator) < abs(denominator)) range = abs(numerator);

        for(int j = range; j>=2; j--){
            if(numerator % j == 0 && denominator % j == 0){
                numerator /= j;
                denominator /= j;
            }
        }

        
        return {numerator, denominator};
    }
    string fractionAddition(string expression) {
        if(isdigit(expression[0])){
            expression = "+" + expression;
        }
        stack<string> st;
        
        int i = 0;
        int currNum = 0, currDen = 1;
        while( i < expression.size()){
            string num = "", den = "";
            if(expression[i] == '-' || expression[i] == '+'){
                num += expression[i];
                i++;
                while(i < expression.size() && expression[i] != '/'){
                    num += expression[i];
                    i++;
                }
                while(i < expression.size() && expression[i] != '+' && expression[i] != '-'){
                    if(expression[i] == '/'){
                        i++;
                    }
                    den += expression[i];
                    i++;
                }
                
                int n = stoi(num), d = stoi(den);
                n = (n*currDen) + (currNum*d);
                d = (d * currDen);
                pair<int, int> p = reduceFraction(n, d);
                currNum = p.first;
                currDen = p.second;
            }
        }

        return (to_string(currNum) + "/" + to_string(currDen));
    }
};