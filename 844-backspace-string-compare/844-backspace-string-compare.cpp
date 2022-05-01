class Solution {
public:
    string process(string s){
        stack<char> stack;
        string res;
        for (char i : s) {
            if (i == '#') {
                if (!stack.empty())
                    stack.pop();
            } else {
                stack.push(i);
            }
        }
        while (!stack.empty()) {
            res += stack.top();
            stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool backspaceCompare(string s, string t) {
        string cleanedS, cleanedT;
        cleanedS = process(s);
        cleanedT = process(t);
        if (cleanedS == "" and cleanedT == "") {
            return true;
        }
        return cleanedS == cleanedT;
    }
};