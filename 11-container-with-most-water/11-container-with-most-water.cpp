class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1,cur,mx = 0;
        while(i < j){
            cur = (j - i) * min(height[i],height[j]);
            mx = max(mx,cur);
            if(height[i] < height[j]){
                i++;
            } else {
                j--;
            }
        }
        return mx;
    }
};