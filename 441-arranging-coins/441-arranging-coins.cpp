class Solution {
public:

    int arrangeCoins(int n) {
        int ret =  (int)(sqrt(2*(long)n+0.25)-0.5);
        return ret;
    }
    
    
};