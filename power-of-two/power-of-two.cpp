class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool ret=false;
        
        if(n<=0)
            return ret;
            
        ret=(n&(n-1))==0?true:false;
        
        return ret;
    }
};