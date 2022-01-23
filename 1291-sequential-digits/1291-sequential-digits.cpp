class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums,res;
        for(int i = 1; i <= 8; i++){
            int num = i;
            int dif = i * 10 + 1;
            for(int j = 0; j < 9 - i; j++){
                num += dif;
                nums.push_back(num);
                dif = dif * 10 + 1;
            }
        }
        sort(nums.begin(),nums.end());
        for(int i : nums){
            if(low <= i and i <= high){
                res.push_back(i);
            }
        }
        return res;
    }
};