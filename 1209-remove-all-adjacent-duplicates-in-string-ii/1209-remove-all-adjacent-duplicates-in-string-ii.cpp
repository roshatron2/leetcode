class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stack;
        for(char i : s){
            if(!stack.empty() and stack.top().first == i){
                stack.push({i,stack.top().second + 1});
            } else {
                stack.push({i,1});
            }
            if(stack.top().second == k){
                for(int j = 0; j < k; j++){
                    stack.pop();
                }
            }
        }
        string res;
        while(!stack.empty()){
           res += stack.top().first; 
           stack.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};