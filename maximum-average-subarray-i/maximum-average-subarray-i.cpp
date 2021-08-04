class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        double mx = (double)sum / k;
        for(int i = k; i < nums.size(); i++){
            cout<<sum<<endl;
            sum += nums[i] - nums[i - k];
            mx = max(mx,(double)sum / k);
        }
        return mx;
    }
};