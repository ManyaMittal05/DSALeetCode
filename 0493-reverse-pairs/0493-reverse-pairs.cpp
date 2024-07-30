class Solution {
public:

    int myCount = 0;
    void merge(vector<int>& arr, int left, int mid, int right){
        int i = left, j = mid+1;
        vector<int> temp;
        while(i <= mid && j <= right){
            if(arr[i] > arr[j]){
                temp.push_back(arr[j]);
                j++;
            }
            else{
                temp.push_back(arr[i]);
                i++;
            }
        }

        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }

        while(j <= right){
            temp.push_back(arr[j]);
            j++;
        }

        for(int i = left; i<=right; i++){
            arr[i] = temp[i - left];
        }
    }

    void countPairs(vector<int>& nums, int left, int mid, int right){
        int j = mid+1;
        for(int i = left; i<=mid; i++){
            while(j <= right && (long long)nums[i] > (long long)2*nums[j]) j++;
            myCount += (j - (mid + 1));
        }
    }

    void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right){
            return;
        }

        int mid = (left + right)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        countPairs(nums, left, mid, right);
        merge(nums, left, mid, right);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return myCount;
    }
};