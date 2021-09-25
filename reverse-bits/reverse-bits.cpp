class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        uint32_t pow=31;
        
        if(n==0)
            return 0;
        
        while(pow!=-1) {
            ret+= (n&0x01)<<pow;
            n=n>>1;
            pow--;
        }
        
        return ret;
    }
};