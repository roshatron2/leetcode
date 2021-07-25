class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> combination,vector<int> candidates,int target,int begin){
        if(target == 0){
            res.push_back(combination);
            return;
        }
        for(int i = begin; i < candidates.size(); i++){
            if(i > begin and candidates[i] == candidates[i-1])
                continue;
            int idx = i;
            int cur = candidates[idx];
            if(target - cur < 0)
                break;
            combination.push_back(cur);
            dfs(combination,candidates,target - cur,i + 1);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        dfs(combination,candidates,target,0);
        return res;
    }
};