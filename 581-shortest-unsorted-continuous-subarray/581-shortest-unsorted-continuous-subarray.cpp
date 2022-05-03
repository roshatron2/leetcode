class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r = n - 1;
        while(l + 1 < n and nums[l] < nums[l + 1])
            l++;
        while(r - 1 >= 0 and nums[r - 1] < nums[r])
            r--;
        int mx = INT_MIN,mn = INT_MAX;
        for(int k = l; k <= r; k++){
            mx = max(mx,nums[k]);
            mn = min(mn,nums[k]);
        }
        int start,end,len;
        for(int i = 0; i < n; i++){
            if(nums[i] > mn){
                start = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] < mx){
                end = i;
                break;
            }
        }
        len = end - start + 1;
        return len > 0 ? len : 0;
    }
};
/*
0 1 2 3  4 5 6
2 6 4 8 10 9 15
i = 1
j = 5
mn = 4
mx = 10
start = 1
end = 5
len = 
*/