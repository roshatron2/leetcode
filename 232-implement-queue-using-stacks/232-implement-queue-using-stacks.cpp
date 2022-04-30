class MyQueue {
public:
    stack<int> stack1,stack2;
    int front; 
    MyQueue() {
        
    }
    void push(int x) {
       if(stack1.empty()){
           front = x;
       } 
       stack1.push(x); 
    }
    
    int pop() {
       while(!stack1.empty()){
           stack2.push(stack1.top());
           stack1.pop();
       }
       int top = stack2.top();
       stack2.pop();
       if(!stack2.empty()) 
          front = stack2.top();
       while(!stack2.empty()){
           stack1.push(stack2.top());
           stack2.pop();
       }
       return top;
    }
    
    int peek() {
       return front; 
    }
    
    bool empty() {
       return stack1.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
/*
stack1 : 2 3 4 
stack 2:  

*/