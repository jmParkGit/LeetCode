class Solution {
private:
    int calculateNextN(int n) {
        int ret=0;
        
        while(n) {
            int remainder=n%10;
            ret+=remainder*remainder;
            n=n/10;
        }
        
        return ret;
    }
public:
    bool isHappy(int n) {
        bool ret=false;
        map<int,bool> m;
        
        while(true) {
            if(n==1) {
                ret=true;
                break;
            } 
            
            if(m.find(n)!=m.end()) {
                ret=false;
                break;
            }
            else {
                m.insert({n,true});
            }
            
            n=calculateNextN(n);
        }
        
        return ret;    
    }
};