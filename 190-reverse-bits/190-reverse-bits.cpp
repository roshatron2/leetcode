class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i <= 31; i++){
            int bit = n >> i & 1;
            res = res * 2 + bit;
        }
        return res;
    }
};