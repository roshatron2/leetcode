class Solution {
public:
    int search(vector<int> &nums,int l,int r,int target){
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(target < nums[mid]){
                r = mid - 1;
            } else if(target > nums[mid]){
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int found;
        for(int i = 0; i < numbers.size(); i++){
            int cmp = target - numbers[i];
            if(cmp < numbers[i]){
                found = search(numbers,0,i - 1,cmp);
                if(found >= 0){
                    res = {i + 1,found + 1};
                    break;
                }
            } else {
                found = search(numbers,i + 1,numbers.size() - 1,cmp);
                if(found >= 0){
                    res = {i + 1,found + 1};
                    break;
                }
            }
        }
        return res;
    }
};