class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, int target, int k, vector<int> cur){
        if(target == 0){
            res.push_back(cur);
            return;
        }
        if(target < 0 or k >= candidates.size()){
            return;
        }
        for(int i = k; i < candidates.size(); i++){
            cur.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       dfs(candidates, target, 0, {}); 
       return res;
    }
};