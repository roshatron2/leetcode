class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> candidates,int target,vector<int> combination,int begin){
        if(target == 0){
            res.push_back(combination);
            return;
        }
        if(target < 0)
            return;
        for(int i = begin; i < candidates.size(); i++){
            combination.push_back(candidates[i]);
            dfs(candidates,target - candidates[i],combination,i);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target,{},0);
        return res;
    }
};