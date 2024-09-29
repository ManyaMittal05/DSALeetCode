class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool helper(vector<vector<char>>& board, int n, int m, int i, int j,
                string word, int ind) {
        if (ind == word.size())
            return true;

        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '#') {
            return false;
        }
        if (board[i][j] != word[ind])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';

        for (auto& d : dir) {
            int new_i = i + d[0];
            int new_j = j + d[1];
            if (helper(board, n, m, new_i, new_j, word, ind + 1))
                return true;
        }

        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j < m; j++){
                if(helper(board, n, m, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};