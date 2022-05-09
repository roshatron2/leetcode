class MovingAverage {
public:
    queue<int> q;
    int size;
    int sum = 0;
    MovingAverage(int size) {
       this->size = size; 
    }
    
    double next(int val) {
       if(q.size() < size){
           sum += val;
           q.push(val);
       } else {
           sum -= q.front();
           q.pop();
           q.push(val);
           sum += val;
       }
       return (double)sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */