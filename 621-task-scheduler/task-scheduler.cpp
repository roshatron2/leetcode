class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> heap;    
        unordered_map<char,int> map;
        
        for(char i : tasks){
            map[i]++;
        }
        for(auto [k,v] : map){
           heap.push(v); 
        }
        queue<pair<int,int>> q;
        int top;
        int t = 0;
        while(!heap.empty() or !q.empty()){
            t += 1;
            if(!heap.empty()){
                top = heap.top();
                heap.pop();
                if(top - 1){
                    q.push({top - 1, t + n});
                }
            }
            if(!q.empty() and t == q.front().second){
                heap.push(q.front().first);
                q.pop();
            }
        }
        return t;
    }
};