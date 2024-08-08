class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        //order of directions is - East, South, West, North
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        vector<vector<int>> result;
        result.push_back({rStart, cStart});
        int steps = 0;
        int dir = 0;

        while(result.size() != rows*cols){
            //if the direction is East or West then increment the steps
            if(dir == 0 || dir == 2){
                steps++;
            }

            for(int count = 0; count < steps; count++){
                rStart = rStart + directions[dir][0];
                cStart = cStart + directions[dir][1];
                
                //check if the entry we are going to make is valid or not
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols){
                    result.push_back({rStart, cStart});
                }
            }

            dir = (dir + 1) % 4; //for getting the next direction
        }
        return result;
    }
};