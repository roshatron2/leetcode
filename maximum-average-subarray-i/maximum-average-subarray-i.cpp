class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        int mx = sum;
        for(int i = k; i < nums.size(); i++){
            sum += nums[i] - nums[i - k];
            mx = max(mx,sum);
        }
        return (double)mx/k;
    }
};