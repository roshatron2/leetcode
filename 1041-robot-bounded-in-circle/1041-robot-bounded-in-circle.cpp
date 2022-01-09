class Solution {
public:
    bool isRobotBounded(string instructions) {
        //0 - north
        //1 - east
        //2 - south
        //3  - west
        int dir = 0;
        int x = 0,y = 0;
        for(char i : instructions){
            if(i == 'L'){
                if(dir == 0){
                    dir = 3;
                } else if(dir == 1){
                    dir = 0;
                } else if(dir == 2){
                    dir = 1;
                } else {
                    dir = 2;
                }
            } else if(i == 'R'){
                if(dir == 0){
                    dir = 1;
                } else if(dir == 1){
                    dir = 2;
                } else if(dir == 2){
                    dir = 3;
                } else {
                    dir = 0;
                }
            } else {
                if(dir == 0){
                    y++;
                } else if(dir == 1){
                    x++;
                } else if(dir == 2){
                    y--;
                } else {
                    x--;
                }
            }
        }
        if(x == 0 and y == 0){
            return true;
        }
        if(dir != 0){
            return true;
        }
        return false;
    }
};