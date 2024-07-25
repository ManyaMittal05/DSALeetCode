class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int i = low,  j = mid+1;
        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        
        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= high){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i = low; i<=high; i++){
            nums[i] = temp[i-low];
        }
    }

    void mergeSort(int low, int high, vector<int>& nums){
        if(low >= high) return;

        int mid = (low + high)/2;
        mergeSort(low, mid, nums);
        mergeSort(mid+1, high, nums);
        merge(nums, low, mid, high);
    }


    vector<int> sortArray(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        mergeSort(low, high, nums);
        return nums;
    }
};