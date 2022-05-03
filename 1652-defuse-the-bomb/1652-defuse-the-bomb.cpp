class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int size = code.size();
        vector<int> res(size);
        for(int i = 0; i < size; i++){
            int sum = 0;
            if(k > 0)
                for(int j = 0; j < k; j++){
                    int J = (i + j + 1) % size;
                    sum += code[J];
                }
            else if(k < 0)
                for(int j = 0; j < abs(k); j++){
                    int J = (i - j - 1) % size;
                    sum += code[J < 0 ? size + J : J];
                }
            res[i] = sum;
        }
        return res; 
    }
};