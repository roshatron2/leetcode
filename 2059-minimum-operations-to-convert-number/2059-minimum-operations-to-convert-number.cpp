class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;    
        q.push(start);
        int ops = 0;
        vector<bool> visited(1001,false);
        while(!q.empty()){
           int size = q.size();
           for(int i = 0; i < size; i++){
               int x = q.front();
               if(x == goal)
                   return ops;
               q.pop();
               if(x >= 0 and x <= 1000 and !visited[x]){
                   visited[x] = true;
                   for(int num : nums){
                       q.push(x + num);
                       q.push(x - num);
                       q.push(x ^ num);
                   }
               }
           }
           ops++;
        }
        return -1;
    }
};