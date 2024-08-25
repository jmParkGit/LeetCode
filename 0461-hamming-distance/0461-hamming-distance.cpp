class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = 0;
        int xorVal= x^y;
            
        while(xorVal) {
            int div = xorVal/2;
            int mod = xorVal%2;
            xorVal=div;
            
            if(mod) {
                ret+=1;
            }
        } 
        
        return ret;
    }
};