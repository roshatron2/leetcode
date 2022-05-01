class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        vector<int> res;
        for(int i : nums1){
            map[i] += 1;
        }
        for(int i : nums2){
           if(map[i]){
               res.push_back(i);
               map[i] = 0;
           }         
        }
        return res;
    }
};

/*
1: 2
2: 2

*/