class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;
        vector<int> partitions;

        for(int i = 0; i < s.size(); i++){
            last[s[i]] = i;
        }    
        int l = 0, r = last[s[0]];
        for(int i = 0; i < s.size(); i++){
            if(i > r){
                partitions.push_back(r - l + 1);
                l = i;
            }
            r = max(r, last[s[i]]);
        }
        partitions.push_back(r - l + 1);
        return partitions;
    }
};
