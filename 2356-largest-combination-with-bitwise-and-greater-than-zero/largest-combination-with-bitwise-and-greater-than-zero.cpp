class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> counts(32, 0);    

        for(int candidate : candidates) {
            for(int i = 31; i >= 0; i--){
                int bit = 1 << i & candidate;

                if(bit) {
                    counts[i]++;
                }
            }
        }
        return *max_element(counts.begin(), counts.end());
    }
};