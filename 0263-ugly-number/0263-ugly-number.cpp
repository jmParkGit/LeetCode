class Solution {
private:
    bool calculateUgly(int n) {
        bool ret =false;
        while(0==n%2) {
            n = n/2;
        }

        while(0==n%3) {
            n = n/3;
        }

        while(0==n%5) {
            n = n/5;
        }

        if(1==n) {
            ret = true;
        }
        else {
            ret = false;
        }

        return ret;
    }
public:
    bool isUgly(int n) {
        
        if(1==n) {
            return true;
        }
        else if(0==n) {
            return false;
        }

        return calculateUgly(n);
    }
};