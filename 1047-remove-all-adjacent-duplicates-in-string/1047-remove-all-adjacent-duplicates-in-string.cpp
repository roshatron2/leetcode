class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        for(char i : s){
            if(!stack.empty() and stack.top() == i){
                stack.pop();    
            } else {
                stack.push(i);
            }
        }
        string res;
        while(!stack.empty()){
           res += stack.top();
           stack.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
