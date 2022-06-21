class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(),sum = 0;
        priority_queue<int,vector<int>,greater<int>> heap;
        
        int i = 0;
        while(i < n - 1){
            int jump = heights[i + 1] - heights[i];            
            if(jump > 0){
                heap.push(jump);
                if(heap.size() > ladders){
                    sum += heap.top();
                    heap.pop();
                }
            }
            if(sum > bricks and heap.size() == ladders){
                break;
            }
            i++;
        }
        return i;
    }
};