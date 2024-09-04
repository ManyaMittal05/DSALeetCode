class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> set;
        for(auto o : obstacles){
            pair<int, int> p = {o[0], o[1]};
            set.insert(p);
        }

        char dir = 'N';
        int x = 0, y = 0;
        // if(set.find({0,0}) != set.end()){
        //     commands.erase(commands.begin());
        // }
        int max_dist = 0;
        for(auto command : commands){
            if(command == -1){
                if(dir == 'N') dir = 'E';
                else if(dir == 'E') dir = 'S';
                else if(dir == 'S') dir = 'W';
                else dir = 'N';
            }

            else if(command == -2){
                if(dir == 'N') dir = 'W';
                else if(dir == 'W') dir = 'S';
                else if(dir == 'S') dir = 'E';
                else dir = 'N';
            }

            else{
                for(int i = 1; i <= command; i++){
                    if(dir == 'N'){
                        if(set.find({x, y+1}) == set.end()){
                            y++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(dir == 'E'){
                        if(set.find({x+1, y}) == set.end()){
                            x++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(dir == 'S'){
                        if(set.find({x, y-1}) == set.end()){
                            y--;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        if(set.find({x-1, y}) == set.end()){
                            x--;
                        }
                        else{
                            break;
                        }
                    }
                    max_dist = max(max_dist, x*x + y*y);
                }
            }
        }
        return max_dist;
    }
};