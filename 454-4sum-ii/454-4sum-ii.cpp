class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> map;
        for(int &i : nums1){
            for(int &j : nums2){
                map[i + j] += 1;
            }
        }
        int count = 0;
        for(int &i : nums3){
            for(int &j : nums4){
                int complement = 0 - i - j;
                if(map[complement])
                    count += map[complement];
            }
        }
        return count;
    }
};