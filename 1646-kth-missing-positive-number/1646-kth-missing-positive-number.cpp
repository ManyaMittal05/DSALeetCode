class Solution {
public:
    bool isPresent(vector<int> arr, int ele){
        int low = 0, high = arr.size()-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] == ele) return true;
            else if(arr[mid] < ele) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int low = 1, high = arr[arr.size()-1] + k;
        int size = 0;
        for(int i = low; i<=high; i++){
            if(!isPresent(arr, i)){
                size++;
                if(size == k){
                    return i;
                }
            }
        }
        return -1;
    }
};