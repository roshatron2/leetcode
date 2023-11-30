class KthLargest {
public:
    priority_queue<int,vector<int>, greater<int>> min_heap;
    int k;
    KthLargest(int k, vector<int>& nums) {
       for(int i : nums){
           min_heap.push(i);
       }
       this->k = k;
       while(min_heap.size() > k){
           min_heap.pop();
       }
    }
    
    int add(int val) {
       min_heap.push(val); 
       if(min_heap.size() > k) {
           min_heap.pop();
       }
       return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */