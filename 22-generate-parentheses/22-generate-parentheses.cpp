class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            } else if(s[i] == ')' and st.empty()){
                return false;
            } else {
                st.pop();
            }
        }
        return st.empty();
    }
    vector<string> res;
    void dfs(string cur,int n){
        if(cur.size() == 2 * n){
            if(isValid(cur)){
                res.push_back(cur);
            }
            return;
        }
        dfs(cur + '(',n);
        dfs(cur + ')',n);
    }
    vector<string> generateParenthesis(int n) {
        dfs("",n);
        return res;
    }
};