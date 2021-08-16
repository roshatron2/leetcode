class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        for(int i = 1; i <= nums.size(); i++){
            if(!binary_search(nums.begin(),nums.end(),i)){
               res.push_back(i); 
            }
        }
        return res;
    }
};