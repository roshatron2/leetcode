class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 31; i >= 0; i--){
            int bit = n & 1 << i; 
            if(bit){
                res = res | 1 << 31 - i;  
            }
        }
        return res;
    }
};