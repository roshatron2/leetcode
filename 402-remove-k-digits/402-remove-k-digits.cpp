class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size())
            return "0";
        stack<char> st;
        for(int i = 0; i < num.size(); i++){
            while(!st.empty() and st.top() > num[i] and  k > 0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k){
            st.pop();
            k--;
        }
        string res;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        int i = 0;
        while(res[i] == '0') i++;
        res = res.substr(i);
        return res == "" ? "0" : res;
    }
};
