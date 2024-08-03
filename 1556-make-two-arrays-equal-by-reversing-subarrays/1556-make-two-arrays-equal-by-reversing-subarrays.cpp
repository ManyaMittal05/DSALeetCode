class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> map(1001, 0);
        for(int i = 0; i<target.size(); i++){
            map[target[i]]++;
        }        
        
        for(int i = 0; i<arr.size(); i++){
            map[arr[i]]--;
        }

        for(int i = 0; i < 1001; i++){
            if(map[i] != 0)
                return false;
        }
        return true;
    }
};