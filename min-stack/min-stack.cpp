class MinStack {
public:
    /** initialize your data structure here. */
    struct Node {
        int val,min;
        Node *next;
        Node(int x,int m,Node *n){
            val = x;
            min = m;
            next = n;
        }
    } *head = NULL;
   
    void push(int val) {
        if(!head){
            head = new Node(val,val,head);
        } else {
            head = new Node(val,min(val,head->min),head);
        }
    }
    
    void pop() {
        head = head->next;     
    }
    
    int top() {
        return head ? head->val : NULL;
    }
    
    int getMin() {
        return head ? head->min : NULL;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */