class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> starts = {12,23,34,45,56,67,78,89};
        vector<int> difs = {11,21,31,41,51,61,71,81};
        vector<int> nums = starts;
        vector<int> res;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < starts.size() - i - 1; j++){
                difs[j] = difs[j] * 10 + 1;
                starts[j] += difs[j];
                nums.push_back(starts[j]);
            }
        }
        for(int i : nums){
            if(low <= i and i <= high){
                res.push_back(i);
            }
        }
        return res;
    }
};