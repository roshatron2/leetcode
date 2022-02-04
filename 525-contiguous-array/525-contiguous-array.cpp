class Solution {
public:
    int findMaxLength(vector<int>& nums){
        int count = 0;
        unordered_map<int,int> map;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                count--;
            } else {
                count++;
            }
            if(count == 0){
                ans = max(ans,i + 1);
            } else {
                if(map.find(count) != map.end()){
                    ans = max(ans,i - map[count]);
                } else {
                    map[count] = i;
                }
            }
           
        }
        return ans;
    }
};