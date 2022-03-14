class Solution {
public:
    string simplifyPath(string path) {
        string res,word;
        stringstream ss(path);
        stack<string> st;
        while(getline(ss,word,'/')){
            if(word == ".."){
                if(!st.empty())
                    st.pop();
                continue;
            } else if(word == "."){
                continue;
            }
            if(!word.empty()){
                reverse(word.begin(),word.end());
                st.push(word);
            }
        }
        while(!st.empty()){
            res += st.top();
            res += '/';
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res.empty() ? "/" : res;
    }
};