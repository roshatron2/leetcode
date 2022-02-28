class Solution {
public:
    string getRange(int a,int b){
        if(a == b)
            return to_string(a);
        return to_string(a) + "->" + to_string(b);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int pre = lower - 1;
        vector<string> res;
        for(int i = 0; i <= nums.size(); i++){
            int cur = (i < nums.size()) ? nums[i] : upper + 1;
            if(cur - pre >= 2){
                res.push_back(getRange(pre + 1,cur - 1));
            }
            pre = cur;
        }
        return res;
    }
};