class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string token : tokens){
            if(token == "+" or token == "-" or token == "*" or token == "/"){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int res;
                if(token == "+"){
                    res = op1 + op2;
                } else if(token == "-"){
                    res = op2 - op1;
                } else if(token == "*"){
                    res = op2 * op1;
                } else if (token == "/"){
                    res = op2 / op1;
                }
                st.push(res);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};