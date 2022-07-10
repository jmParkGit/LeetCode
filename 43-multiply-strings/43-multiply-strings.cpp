class Solution {
private:
    string multiplyOne(string num1, char n, int depth) {
        string ret;
        int c=0;
        
        for(int i=num1.length()-1; i>=0; i--) {
            int val=((num1[i]-'0') * (n-'0')) +c;
            c=val/10;
            val=val%10;
            ret.insert(0,to_string(val));
        }
        
        if(1<=c) {
            ret.insert(0,to_string(c));
        }
        
        for(int i=0; i<depth; i++) {
            ret=ret+'0';
        }
        
        return ret;
    }

string add(string num1, string num2) {
    string ret;
    int c=0;
    int num1_index=num1.length()-1;
    int num2_index=num2.length()-1;
    
    
    while(num1_index>=0) {
        
        int val=((num1[num1_index]-'0') + (num2[num2_index]-'0')) +c;
        c=val/10;
        val=val%10;
        
        ret.insert(0,to_string(val));
        
        num1_index--;
        num2_index--;
    }
    
    while(num2_index>=0) {
        int val=(num2[num2_index]-'0') +c;
        c=val/10;
        val=val%10;
        
        ret.insert(0,to_string(val));
        
        num2_index--;
    }
    
    if(1<=c) {
        ret.insert(0,to_string(c));
    }
    
    return ret;
}
    
public:
    string multiply(string num1, string num2) {
        string ret;
        int depth=0;
        
        if(num1.length()==1 && num1[0]=='0') {
            return "0";
        }
        
        if(num2.length()==1 && num2[0]=='0') {
            return "0";
        }
        
        for(int i=num2.size()-1; i>=0;i--) {
            ret=add(ret,multiplyOne(num1,num2[i],depth++));
        }
        
        return ret;
    }
};