class node{
    public:
    int data, i, j;
    node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node*, vector<node*>, compare> minHeap;

        int mini = INT_MAX, maxi = INT_MIN;
        int k = nums.size();
        for(int i = 0; i<k; i++){
            minHeap.push(new node(nums[i][0], i, 0));
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
        }
        int start = mini, end = maxi;

        while(!minHeap.empty()){
            node* temp = minHeap.top();
            minHeap.pop();
            mini = temp->data;
            int i = temp->i;
            int j = temp->j;

            if(maxi - mini < end - start){
                end = maxi;
                start = mini;
            }

            if(j + 1 < nums[i].size()){
                minHeap.push(new node(nums[i][j+1], i, j+1));
                maxi = max(maxi, nums[i][j+1]);
            }
            else{
                break;
            }
        }

        return {start, end};

    }
};