class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int &i : nums){
            int cur = abs(i);
            if(nums[cur - 1] > 0){
                nums[cur - 1] *= -1;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                res.push_back(i + 1);
            }
        }
        return res;
    }
};