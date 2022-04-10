class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(string i : ops){
             if(i == "+"){
                int last = st.top();
                st.pop();
                int second_last = st.top();
                st.push(last);
                st.push(last + second_last);
            } else if(i == "D"){
                st.push(st.top() * 2);
            } else if(i == "C"){
               st.pop(); 
            } else {
                 st.push(stoi(i));
             }
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};