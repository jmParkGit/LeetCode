class Solution {
private:
    int calculateSum(int num) {
        int ret=0;
        while(num) {
            ret+=num%10;
            num/=10;
        }
        
        return ret;
    }
public:
    int addDigits(int num) {
        int ret=num;
        
        while(10<=ret) {
            ret=calculateSum(ret);
        }
        
        return ret;
    }
};