class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        
        vector<string> number;
        for(int i = 0; i<nums.size(); i++){
            string num = bitset<32>(nums[i]).to_string();
            num = num.substr(num.find('1'));
            number.push_back(num);
        }
        
        string concatenated  = number[0] + number[1] + number[2];
        int decimalValue = stoi(concatenated, nullptr, 2);

        concatenated = number[0] + number[2] + number[1];
        decimalValue = max(decimalValue, stoi(concatenated, nullptr, 2));

        concatenated = number[1] + number[0] + number[2];
        decimalValue = max(decimalValue, stoi(concatenated, nullptr, 2));
        
        concatenated = number[1] + number[2] + number[0];
        decimalValue = max(decimalValue, stoi(concatenated, nullptr, 2));

        concatenated = number[2] + number[0] + number[1];
        decimalValue = max(decimalValue, stoi(concatenated, nullptr, 2));

        concatenated = number[2] + number[1] + number[0];
        decimalValue = max(decimalValue, stoi(concatenated, nullptr, 2));


        return decimalValue;
    }
};