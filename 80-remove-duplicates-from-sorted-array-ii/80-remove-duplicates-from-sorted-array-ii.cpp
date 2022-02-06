class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> map;
        for(int i : nums){
            map[i]++;
        }
        int len = 0;
        int j = 0; 
        for(auto [k,v] : map){
            int count = v > 2 ? 2 : v;
            len += count;
            for(int i = 0; i < count; i++){
                nums[j++] = k;
            }
        }
        nums = vector<int>(nums.begin(),nums.begin() + len);
        return nums.size();
    }
};