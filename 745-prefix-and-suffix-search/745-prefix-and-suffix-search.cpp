class WordFilter {
public:
    unordered_map<string,int> map;
    WordFilter(vector<string>& words) {
       for(int i = 0; i < words.size(); i++){
          int size = words[i].size();
          for(int j = 1; j <= size; j++){
              string prefix = words[i].substr(0,j);
              for(int k = 0; k < size; k++){
                  string suffix = words[i].substr(k);
                  map[prefix + '|' + suffix] = i + 1;
              }
          }
       } 
    }
    
    int f(string pref, string suff) {
       return map[pref + '|' + suff] - 1;  
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */