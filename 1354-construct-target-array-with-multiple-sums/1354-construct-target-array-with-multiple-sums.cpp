class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> max_heap;
        long long sum = 0;
        if(target.size() == 1){
            return target[0] == 1;
        }
        for(int i : target){
            max_heap.push(i);
            sum += i;
        }
        
        while(max_heap.top() > 1){
            int largest = max_heap.top();
            max_heap.pop();
            int rest = sum - largest;
            if(rest == 1)
                return true;
            int x = largest % rest;
            if(x == 0 or x == largest)
                return false;
            sum += x - largest;
            max_heap.push(x);
        }
        return true;
    }
};