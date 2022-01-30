class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> map;
        for(int i : nums){
            map[i]++;
        }
        int k = 0;
        for(auto [num,count] : map){
            for(int i = 0; i < count; i++){
                nums[k++] = num;
            }
        }
    }
};