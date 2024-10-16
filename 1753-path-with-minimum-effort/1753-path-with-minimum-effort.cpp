class Solution {
public:
    typedef pair<int, pair<int, int>> pipii; //{effort, {row, col}}
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        int row = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> efforts(row, vector<int>(cols, INT_MAX));
        efforts[0][0] = 0;

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto topEle = pq.top();
            int eff = topEle.first;
            int i = topEle.second.first;
            int j = topEle.second.second;
            pq.pop();

            if (i == row - 1 && j == cols - 1)
                return eff;

            for (auto& d : dir) {
                int new_i = i + d[0];
                int new_j = j + d[1];

                if (new_i >= 0 && new_i < row && new_j >= 0 && new_j < cols) {
                    int newEffort =
                        max(abs(heights[i][j] - heights[new_i][new_j]), eff);
                    if (efforts[new_i][new_j] > newEffort) {
                        efforts[new_i][new_j] = newEffort;
                        pq.push({newEffort, {new_i, new_j}});
                    }
                }
            }
        }
        return -1;
    }
};