class Solution {
public:
    unordered_map<string,bool> memo; 
    bool dfs(string s,string t,string st,int i,int j,int k){
        string key = to_string(i) + "." + to_string(j) + "." + to_string(k);
        if(memo.count(key)){
            return memo[key];
        }
        if(st.size() == k)
            return true;
        bool ans = false;
        if(i < s.size() and s[i] == st[k]){
            ans |= dfs(s,t,st,i + 1,j,k + 1);
        }
        if(j < t.size() and t[j] == st[k]){
            ans |= dfs(s,t,st,i,j + 1,k + 1);
        } 
        return memo[key] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
       if(s1.size() + s2.size() != s3.size())
           return false;
       return dfs(s1,s2,s3,0,0,0); 
    }
};