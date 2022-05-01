class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        vector<int> res;
        for(int i : nums1){
            set.insert(i);
        }
        for(int i : nums2){
            auto it = set.find(i);
            if(it != set.end()){
                res.push_back(i);
                set.erase(it);
            }
        }
        return res;
    }
};
