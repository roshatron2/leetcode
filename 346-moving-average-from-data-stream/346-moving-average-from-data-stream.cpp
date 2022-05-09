class MovingAverage {
public:
    queue<int> q;
    int size;
    MovingAverage(int size) {
       this->size = size; 
    }
    
    double next(int val) {
       int sum = 0;
       if(q.size() < size){
           q.push(val);
       } else {
           q.pop();
           q.push(val);
       }
       for(int i = 0; i < q.size(); i++){
           sum += q.front();
           q.push(q.front());
           q.pop();
       }
       return (double)sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */