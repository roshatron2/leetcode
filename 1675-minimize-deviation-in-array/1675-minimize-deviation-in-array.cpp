class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans = INT_MAX,mn = INT_MAX;
        priority_queue<int> pq;
        for(int i : nums){
            i = i % 2 ? i * 2 : i;
            pq.push(i);
            mn = min(mn,i);
        }
        while(pq.top() % 2 == 0){
            ans = min(ans,pq.top() - mn);
            mn = min(pq.top() / 2,mn);
            pq.push(pq.top() / 2);
            pq.pop();
        }
         return min(ans, pq.top() - mn);
    }
};