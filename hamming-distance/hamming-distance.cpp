class Solution {
public:
    int hammingDistance(int x, int y) {
        int ham = 0;
        while(x or y){
            int xbit = x % 2;
            int ybit = y % 2;
            if(xbit != ybit)
                ham++;
            x /= 2;
            y /= 2;
        }
        return ham;
    }
};