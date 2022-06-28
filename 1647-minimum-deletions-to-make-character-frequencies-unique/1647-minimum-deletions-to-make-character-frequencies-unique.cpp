class Solution {
public:
    int minDeletions(string s) {
        priority_queue<int> max_heap;
        vector<int> map(26,0);
        for(char i : s){
            map[i - 'a']++;
        }
        for(int i : map){
            if(i){
                max_heap.push(i);
            }
        }
        int deletions = 0;
        while(max_heap.size() > 1){
            int top = max_heap.top();
            max_heap.pop();
            if(top == max_heap.top()){
               if(top - 1 > 0)
                   max_heap.push(top - 1);
               deletions++;
            }
        }
        return deletions;
    }
};