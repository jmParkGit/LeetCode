class MinStack {
private:
    //int minVal=2147483647;//2^31-1
    vector<int> stk;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push_back(val);
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        int minVal=2147483647;//2^31-1
        
        for(int val : stk)
        {
            if(val<minVal)
                minVal=val;
        }
        
        return minVal;
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