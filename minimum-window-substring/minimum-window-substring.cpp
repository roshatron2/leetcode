class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(counter){
                map[s[end]]--;
                if(map[s[end]] >= 0)
                    counter--;
                end++;
            }
            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                map[s[begin]]++;
                if(map[s[begin]] > 0)
                    counter++;
                begin++;
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
};