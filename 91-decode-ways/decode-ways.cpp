class Solution {
public:
    unordered_map<int,int> memo;
    bool isValid(string s){
        if(s.empty()){
            return true;
        }
        int num = stoi(s);
        if(num >= 1 and num <= 26){
            return true;
        }
        return false;
    }
    int dfs(int i, string s){
        if(memo[i]){
            return memo[i];
        }
        if(i == s.size()){
            return 1;
        } 
        if(i >= s.size()){
            return 0;
        }
        string pick_one = s.substr(i, 1);
        string pick_two = s.substr(i, 2);
        int count = 0;
        if(pick_one[0] == '0')
            return 0;           
        if(isValid(pick_one))
            count += dfs(i + 1, s);
        if(isValid(pick_two))
            count += dfs(i + 2, s);
        return memo[i] = count;
    }
    int numDecodings(string s) {
        return dfs(0, s);
    }
};
/*
*/