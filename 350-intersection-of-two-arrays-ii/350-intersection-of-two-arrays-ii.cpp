class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        for(int i : nums1){
            map[i]++;
        }
        vector<int> intersection;
        for(int i : nums2){
            if(map[i]){
                intersection.push_back(i);
                map[i]--;
            }
        }
        return intersection;
    }
};