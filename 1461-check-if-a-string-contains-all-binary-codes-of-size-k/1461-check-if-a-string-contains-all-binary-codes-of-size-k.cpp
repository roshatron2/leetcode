class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> set;
        for(int i = 0; i <= (int)s.size() - k; i++){
            string subs = s.substr(i,k); 
            set.insert(subs); 
        }
        return set.size() == pow(2,k);
    }
};