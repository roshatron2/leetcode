class Solution {
public:
    int calculate(string s) {
        s += "+0";
        stack<int> st;
        char curOp = '+';
        int num = 0;
        for(char i : s){
            if(isdigit(i)){
               num = (num * 10) + (i - '0');
            } else if(!isdigit(i) and !isspace(i)){
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
                num = 0;
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