class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> subsets = {{}};
        vector<vector<int>> res;
        vector<int> nums;
        for(int i = 1; i <= n; i++){
            nums.push_back(i);
        }
        for(int num : nums){
            int size = subsets.size();
            for(int i = 0; i < size; i++){
                subsets.push_back(subsets[i]);
                subsets.back().push_back(num);
            }
        }
        for(auto set : subsets){
            if(set.size() == k)
                res.push_back(set);
        }
        return res;
    }
};