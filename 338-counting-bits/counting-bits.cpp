class Solution {
public:
    int hammingWeight(int n){
        int weight = 0;
        for(int i = 31; i >= 0; i--){
            int num = 1 << i;
            if(num & n){
                weight++;
            }
        }
        return weight;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; i++){
            res.push_back(hammingWeight(i));
        }
        return res;
    }
};