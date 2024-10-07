class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        vector<int> even, odd;
        
        for(int i = 0; i<3; i++){
            if(nums[i] % 2 == 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        
        if(even.size() > 1) sort(even.begin(), even.end());
        if(odd.size() > 1) sort(odd.rbegin(), odd.rend());
        
        vector<string> number;
        for(int i = 0; i<odd.size(); i++){
            string num = bitset<32>(odd[i]).to_string();
            num = num.substr(num.find('1'));
            number.push_back(num);
        }
        for(int i = 0; i<even.size(); i++){
            string num = bitset<32>(even[i]).to_string();
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