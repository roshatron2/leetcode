class Solution {
public:
    vector<vector<int>> res;
    vector<int> candidates;
    void dfs(int start, int target, vector<int> cur){
        if(target == 0){
            res.push_back(cur);
            return;
        }
        if(target < 0){
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(i != start and candidates[i] == candidates[i - 1]){
                continue;
            }
            cur.push_back(candidates[i]);
            dfs(i + 1, target - candidates[i], cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(), candidates.end());
       this->candidates = candidates; 
       dfs(0, target, {});
       return res;
    }
};