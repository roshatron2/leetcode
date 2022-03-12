class Solution {
public:
    int calculate(string s) {
        s += "+ 0";
        string cur;
        stack<int> st;
        char curOp = '+';
        for(char i : s){
            if(isdigit(i)){
               cur += i; 
            } else if(!isdigit(i) and !isspace(i)){
                int num = stoi(cur);
                cur = "";
                if(curOp == '+'){
                    st.push(num);
                } else if(curOp == '-'){
                    st.push(-num);
                } else if(curOp == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                } else if(curOp == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                curOp = i;
            }
        }
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};