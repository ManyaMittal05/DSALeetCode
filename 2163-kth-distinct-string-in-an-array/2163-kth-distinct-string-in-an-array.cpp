class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> freq;
        for(auto s : arr){
            freq[s]++;
        }
        int occurence = 0;
        for(auto s : arr){
            if(freq[s] == 1){
                occurence++;
                if(occurence == k)
                    return s;
            }
        }
        return "";
    }
};