class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int ret=0;
        int q1Size=0;
        int q2Size=0;
        
        q1Size=q1.size();
        for(int i=0; i<q1Size-1; i++) {
            q2.push(q1.front());
            q1.pop();
        }
        
        ret=q1.front();
        q1.pop();
        
        q2Size=q2.size();
        for(int i=0; i<q2Size; i++) {
            q1.push(q2.front());
            q2.pop();
        }
        
        return ret;
    }
    
    int top() {
        return q1.back();
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