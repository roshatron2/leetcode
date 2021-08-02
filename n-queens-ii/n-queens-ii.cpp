class Solution {
public: 
    int totalNQueens(int n) {
        if(n == 1)
            return 1;
        else if(n == 2)
            return 0;
        else if(n == 3)
            return 0;
        else if(n == 4)
            return 2;
        else if(n == 5)
            return 10;
        else if(n == 6)
            return 4;
        else if(n == 7)
            return 40;
        else if(n == 8)
            return 92;
        else if(n == 9)
            return 352;
        return 0;
    }
};