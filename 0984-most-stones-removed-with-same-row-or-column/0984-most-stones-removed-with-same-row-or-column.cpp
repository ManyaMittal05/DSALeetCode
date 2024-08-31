class Solution {
public:
    //we will apply dfs algorithm here
    //mark the stones with any coordinate same to current stone as visited
    //we will be calling dfs on all the stones by checking if they are not visited 
    //and will mark all the stones in same row and column as visited
    //after each dfs call we will increment the count of valid stones
    //number of stones removed = total stones - valid stones 
    void dfs(int ind, int n, vector<vector<int>>& stones, vector<bool>& visited){
        visited[ind] = true;

        for(int i = 0; i<n; i++){
            if(!visited[i]){
                if(stones[ind][0] == stones[i][0]){
                    dfs(i, n, stones, visited);
                }
                if(stones[ind][1] == stones[i][1]){
                    dfs(i, n, stones, visited);
                }
            }
        } 
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int valid = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(i, n, stones, visited);
                valid++;
            }
        }

        return n - valid;
    }
};