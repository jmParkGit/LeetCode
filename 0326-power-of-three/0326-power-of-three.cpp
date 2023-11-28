class Solution {
public:
    bool isPowerOfThree(int n) {
        bool ret=true;

        if(n<=0) {
            return false;
        }

        while(3<=n) {
            if(0!=n%3) {
                ret = false;
                break;
            }
            n = n/3;
        }
        
        if(2==n) {
            ret = false;
        }

        return ret;
    }
};