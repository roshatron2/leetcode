class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> set(words.begin(),words.end());
        
        for(string word : words){
            for(int k = 1; k < word.size(); k++){
                string substring = word.substr(k);
                set.erase(substring);    
            }
        }
        int res = 0;
        for(string word : set){
            res += word.size() + 1;
        }
        return res;
    }
};