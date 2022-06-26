class Solution {
private:
    int isNumber(char s) {
        int ret=-1;
        
        if(s<'0' || '9'<s)
            return ret;
        
        ret = s-'0';
        
        return ret;
    }
    
    int calculateIntergerFromStr(string s) {
        long long ret=0;
        bool isMinus=false;
        bool hasRet=false;
        
        for(int i=0; i<s.length(); i++) {
            if(' '==s[i]) {
                if(hasRet)
                    break;
                
                continue;
            }
            else if('-'==s[i]) {  
                if(hasRet)
                    break;
                
                isMinus=true;
                if(i>=s.length() || isNumber(s[i+1])==-1 ) {
                    return 0;
                }
                continue;
            }
            else if('+'==s[i]) {
                
                if(hasRet)
                    break;
                
                if(i>=s.length() || isNumber(s[i+1])==-1 ) {
                    return 0;
                }
                continue;
            }
            
            int n= isNumber(s[i]);
            if(-1 == n)
                break;
            
            if(isMinus) {
                if(ret>=(long long)INT_MAX+1)
                    return INT_MIN;
            } else {
                if(ret>=(long long)INT_MAX)
                    return INT_MAX;
            }
            
            ret*=10;
            ret+=n;
            hasRet=true;
        }
        
        if(isMinus)
            ret*=-1;
        
        if(ret>=(long long)INT_MAX)
        {
            ret=INT_MAX;
        } else if(ret<=(long long)INT_MIN) {
            ret=INT_MIN;
        } else {
            //ret=ret;
        }
        
        return (int)ret;
    }
public:
    int myAtoi(string s) {
        int ret=0;
        
        ret= calculateIntergerFromStr(s);
        
        return ret;
    }
};