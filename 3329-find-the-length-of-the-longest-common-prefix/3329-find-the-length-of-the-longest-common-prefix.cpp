class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> set;

        //putting all the possible prefixes from arr1 in set
        for(int i = 0; i<arr1.size(); i++){
            int num = arr1[i];

            while(num != 0){
                set.insert(num);
                num = num / 10;
            }
        }

        int result = 0;
        for(int i = 0; i<arr2.size(); i++){
            int num = arr2[i];
            while(num != 0){
                if(set.find(num) != set.end()){
                    result = max(result, num);
                    break;
                }
                num = num / 10;
            }
        }

        int length = 0;
        while(result != 0){
            length++;
            result = result / 10;
        }
        return length;
    }
};