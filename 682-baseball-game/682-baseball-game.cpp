class Solution {
private:
    int getInteger(string s) {
        bool isMinus=false;
        int ret=0;
        
        for(int i=0; i<s.length(); i++) {
            if('-'==s[i]) {
                isMinus=true;
                continue;
            }
            ret=ret*10;
            ret+=s[i]-'0';
        }
        
        if(isMinus) {
            ret *= -1;
        }
        
        return ret;
    }
    
public:
    int calPoints(vector<string>& ops) {
        vector<int> stk;
        int ret=0;
        
        for(int i=0; i<ops.size(); i++) {
            
            if("+" == ops[i]) {
                int ss=stk.size();
                int add=stk[ss-2]+stk[ss-1];
                stk.push_back(add);
            } else if("D" == ops[i]) {
                int d=stk.back() * 2;
                stk.push_back(d);
            } else if("C" == ops[i]) {
                stk.pop_back();
            } else {
                stk.push_back(getInteger(ops[i]));
            }
        }
        
        for(int i=0; i<stk.size(); i++) {
            ret+=stk[i];
        }
        
        return ret;
    }
};