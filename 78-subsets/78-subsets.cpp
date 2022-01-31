class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for(int i : nums){
            int size = res.size();
            for(int j = 0; j < size; j++){
                vector<int> cur = res[j];
                cur.push_back(i);
                res.push_back(cur);
            }
        }
        return res;
    }
};