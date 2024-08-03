class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> freq(n, vector<int> (11,0));
        int winner = 0;
        for(auto p : pick){
            freq[p[0]][p[1]]++;
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<11; j++){
                if(freq[i][j] > i){
                    winner++;
                    break;
                }
            }
        }
        return winner;
    }
};