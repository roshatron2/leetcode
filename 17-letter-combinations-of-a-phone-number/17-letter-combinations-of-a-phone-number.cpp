class Solution {
public:
    unordered_map<int, string> map = {{2, "abc"}, {3, "def"}, {4, "ghi"}, 
                                      {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, 
                                      {8, "tuv"},{9, "wxyz"}};
    vector<string> res;
    void dfs(string digits,string cur,int i){
        if(digits.size() == i){
            res.push_back(cur);
            return;
        }
        for(auto x : map[(int)digits[i] - '0']){
            dfs(digits,cur + x,i + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
       if(digits.empty())
           return res;
       dfs(digits,"",0);
        return res;
    }
};