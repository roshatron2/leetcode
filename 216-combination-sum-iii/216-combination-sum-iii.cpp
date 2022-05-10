class Solution {
public:
    vector<vector<int>> res;
    void dfs(int n,int k,int start,vector<int> cur){
       if(n < 0){
           return;
       } 
       if(k == 0 and n == 0){
           res.push_back(cur);
           return;
       }
       for(int i = start; i <= 9; i++){
           cur.push_back(i);
           dfs(n - i,k - 1,i + 1,cur);
           cur.pop_back();
       }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       dfs(n,k,1,{});
       return res;
    }
};