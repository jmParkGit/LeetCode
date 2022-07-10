class Solution {
public:
    string convertToBase7(int num) {
        string ret;
        bool isMinus=false;
        
        if(0==num){
            return "0";
        }
        
        if(0>num) {
            isMinus=true;
            num*=-1;
        }
        
        while(num) {
            int val=num%7;
            num/=7;
            ret.insert(0,to_string(val));
        }
        
        if(isMinus) {
            ret.insert(0,"-");
        }
        
        return ret;
    }
};