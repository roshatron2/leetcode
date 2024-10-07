class Solution {
public:
    int find(string s, string subs){
        size_t pos = s.find(subs);
        return (pos == string::npos) ? -1 : static_cast<int>(pos);
    }
    string replace(string s, int pos){
        return s.substr(0, pos) + s.substr(pos + 2);
    }
    int minLength(string s) {
        if(find(s, "AB") == -1 and find(s, "CD") == -1){
            return s.size();
        }
        int pos = s.find("AB");
        if(pos != -1)
            s = replace(s, pos);
        pos = s.find("CD");
        if(pos != -1)
            s = replace(s, pos);
        return minLength(s);
    }
};