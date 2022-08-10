class Solution {
public:
    string sortSentence(string s) {
        map<int,string> map;    
        string res;
        stringstream ss(s);
        string word;
        while(getline(ss,word,' ')){
            int index = word.back() - '0';
            word.pop_back();
            map[index] = word;
        }
        for(auto [k,v] : map){
            res += v + " ";
        }
        res.pop_back();
        return res;
    }
};
/*
is2 sentence4 This1 a3
1: This
2: is
3: a
4: sentence

*/