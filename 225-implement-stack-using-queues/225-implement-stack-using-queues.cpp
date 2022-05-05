class MyStack {
public:
    MyStack() {
        
    }
    int stackTop;
    queue<int> q1,q2;
    void push(int x) {
       q1.push(x);
       stackTop = x;
    }
    
    int pop() {
        int popped;
        while(q1.size()){
           popped = q1.front();
           q2.push(popped);
           q1.pop();
        }
        while(q2.size() > 1){ 
            stackTop = q2.front();
            q1.push(stackTop);
            q2.pop();
        }
        q2.pop();
        return popped; 
    }
    
    int top() {
       return stackTop; 
    }
    
    bool empty() {
       return q1.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */