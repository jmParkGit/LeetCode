class MyQueue {
private:
    const static int STK_SIZE=100;
    int stk1[STK_SIZE];//in
    int stk2[STK_SIZE];//out
    int stk1Cnt=0;
    int stk2Cnt=0;
    
public:
    MyQueue() {
        stk1Cnt=0;
        stk2Cnt=0;
    }
    
    void push(int x) {
        stk1[stk1Cnt++]=x;
    }
    
    int pop() {
        int ret=0xff;

        if(stk2Cnt) {
            ret = stk2[--stk2Cnt];
            return ret;
        }
        
        if(stk1Cnt) {
            for(int i=stk1Cnt; i>0; i--) {
                stk2[stk2Cnt++]=stk1[i-1];
                
            }
            stk1Cnt=0;
            ret=stk2[--stk2Cnt];
        }
        
        return ret;
    }
    
    int peek() {
        int ret=0xff;

        if(stk2Cnt) {
            ret = stk2[stk2Cnt-1];
            return ret;
        }
        
        if(stk1Cnt) {
            for(int i=stk1Cnt; i>0; i--) {
                stk2[stk2Cnt++]=stk1[i-1];
                
            }
            stk1Cnt=0;
            ret=stk2[stk2Cnt-1];
        }
        
        return ret;
    }
    
    bool empty() {
        bool ret=true;
        
        if(stk1Cnt)
            ret=false;
        
        if(stk2Cnt)
            ret=false;
        
        return ret;
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