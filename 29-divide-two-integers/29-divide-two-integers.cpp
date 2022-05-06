class Solution {
public:
    int divide(int dividend, int divisor) {
        int isPlus=0;
        int ret=0;
        int cc=0;
        const int HALF_INT_MAX=1073741823;

        //exception
        if(divisor==0)
            return 0;
        
        if(dividend==0)
            return 0;
        
        if(divisor==1)
            return dividend;
        
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        
        if(divisor==-1)
            return -dividend;
        
        if(divisor == INT_MIN) {
            if(dividend==INT_MIN) {
                return 1;
            }
            else {
                return 0;
            }
        }
        
        //main
        if(dividend<0) {
            isPlus--;
            
            if(dividend==INT_MIN)
            {
                dividend=INT_MAX;
                cc=1;
            }
            else {
                dividend=-dividend;    
            }
        }
        
        if(divisor<0) {
            isPlus++;
            divisor=-divisor;
        }
        
        
        while(dividend-divisor>=0) {
            int d=divisor;
            int v=1;
            
            
            while(dividend>=d && HALF_INT_MAX>d) {
                dividend-=d;
                ret+=v;
                d+=d;
                v+=v;
            }
            
            if(dividend-divisor>=0 && HALF_INT_MAX<=d)
            {
                dividend-=divisor;
                ret+=1;
            }
            
            if(cc) {
                dividend+=cc;
                cc=0;
            }
            
        }
        
        if(isPlus){
            ret=-ret;
        }
        
        return ret;
    }
};