class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> bits(32,0);
        int i = 0;
        while(n){
            bits[i++] = n % 2;
            n /= 2;
        }
        uint32_t res = 0;
        for(int i : bits){
            res = res * 2 + i;
        }
        return res;
    }
};