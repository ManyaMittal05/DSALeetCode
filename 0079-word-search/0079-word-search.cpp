class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0, -1}, {1, 0}, {-1,0}};
    bool f(vector<vector<char>>& board, int i, int j, int n, int m, string word, int index){
        if(index < 0) return true;
        if(i < 0 || j < 0 || i >= n || j >= m  || board[i][j] == '$'){
            return false;
        }
        if(board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';

        for(auto& d : dir){
            int new_i = i + d[0];
            int new_j = j + d[1];
            if(f(board, new_i, new_j, n, m, word, index-1)){
                return true;
            }
        }
        
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int len = word.length();

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j >= 0; j--){
                if(board[i][j] == word[len-1] && f(board, i, j, n, m, word, len-1))
                    return true;
            }
        }
        return false;
    }
};