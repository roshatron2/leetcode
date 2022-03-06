class Solution {
public:
    void clean(deque<int> &dq,vector<int> &nums,int k,int i){
        if(!dq.empty() and dq.front() == i - k){
                dq.pop_front();
        }
        while(!dq.empty() and nums[i] > nums[dq.back()]){
            dq.pop_back();
        }
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        
        if(k == 1)
            return nums;
        
//         for(int i = 0; i < k;i++){
//             clean(dq,nums,k,i);
//             dq.push_back(i);
//         }
        
//         res.push_back(nums[dq.front()]);
        
        for(int i = 0; i < nums.size(); i++){
            clean(dq,nums,k,i);
            dq.push_back(i);
            if(i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};