class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> open;
        stack<int> close;
        for(char i : s){
            if(open.empty() and close.empty()){
                if(i == '('){
                    open.push(i);
                } else {
                    close.push(i);
                }
            } else if(i == ')') {
                if(!open.empty() and open.top() == '('){
                    open.pop();
                } else {
                    close.push(i);
                }
            } else if(i == '('){
                open.push(i);
            }
        }    
        return open.size() + close.size();
    }
};