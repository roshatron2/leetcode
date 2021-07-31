class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string i : tokens){
            stringstream ss(i);
            int x;
            ss >> x;
            if(i != "+" and i != "/" and i != "*" and i != "-"){
                st.push(x);
            } else {
                char op = i[0];
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                switch(op){
                    case '+' : st.push(op1 + op2);
                        break;
                    case '-' : st.push(op2 - op1);
                        break;
                    case '*' : st.push(op1 * op2);
                        break;
                    case '/' : st.push(op2 / op1);
                        break;
                }
            }
        }
        return st.top();
    }
};