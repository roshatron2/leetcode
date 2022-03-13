class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> map = {{')', '('}, {'}', '{'}, {']', '['}};
        for(char i : s){
            if(i == '(' or i == '{' or i == '['){
                st.push(i);
            } else {
                if(st.empty()){
                    return false;
                }
                if(st.top() == map[i]){
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};