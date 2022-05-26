class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(int i = 31; i >= 0; i--){
            int bit = n >> i;
            bit = bit & 1;
            if(bit){
                count++;
            }
        }    
        return count;
    }
};