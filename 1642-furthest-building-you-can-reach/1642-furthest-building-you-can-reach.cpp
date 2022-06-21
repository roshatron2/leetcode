class Solution {
public:
    bool isReachable(vector<int>& heights,int bricks,int ladders,int pos){
        vector<int> jumps;
        for(int j = 0; j < pos; j++){
                int jump = heights[j + 1] - heights[j];
                if(jump > 0)
                    jumps.push_back(jump);
        }
        sort(jumps.begin(),jumps.end());
        long long int bricksRemaining = bricks,laddersRemaining = ladders;
        bool reachable = true;
        for(int jump : jumps){
            bricksRemaining -= jump;
            if(bricksRemaining < 0){
                laddersRemaining--;
            }
            if(laddersRemaining < 0){
                return false;
            }
        }        
        return true;
    } 
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int l = 0,r = n - 1,ans;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(isReachable(heights,bricks,ladders,mid)){
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};