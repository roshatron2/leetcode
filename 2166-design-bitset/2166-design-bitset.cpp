class Bitset {
public:
    string bits,bits_flipped;
    int bit_count;
    bool flipped = false;
    Bitset(int size) {
      bits = string(size,'0');
      bits_flipped = string(size,'1');  
      bit_count = 0;
    }
    void fix(int idx) {
        if(bits[idx] != '1')
            bit_count++;
        bits[idx] = '1';
        bits_flipped[idx] = '0';
    }
    
    void unfix(int idx) {
        if(bits[idx] != '0')
            bit_count--;
        bits[idx] = '0';
        bits_flipped[idx] = '1';
    }
    
    void flip() {
        swap(bits_flipped,bits);
        bit_count = bits.size() - bit_count;
    }
    
    bool all() {
        if(bit_count == bits.size())
            return true;
        return false;
    }
    
    bool one() {
        if(bit_count >= 1)
            return true;
        return false;
    }
    
    int count() {
        return bit_count;
    }
    
    string toString() {
        return bits;       
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */