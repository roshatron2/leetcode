class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0),right(n,0);
        int sum = 0;
        int mx = height[0];
        
        for(int i = 0; i < height.size(); i++){
            mx = max(mx,height[i]);
            left[i] = mx;
        }
        mx = height[n-1];
        for(int i = n - 1; i >= 0; i--){
            mx = max(mx,height[i]);
            right[i] = mx;
        }
        for(int i = 0; i < n; i++){
            int cur = min(left[i],right[i]) - height[i];
            if(cur > 0)
                sum += cur;
        }
        return sum;
    }
};