class Solution {
private:
    string calculateSum(string s1, string s2) {
        string ret;
        int c=0;
        
        while(s1.length() && s2.length()) {
            int n1=s1.back()-'0';
            int n2=s2.back()-'0';
            int sum=n1+n2+c;
            string a=to_string(sum%10);
            c=sum/10;
            
            ret.insert(0,a);
            
            s1.pop_back();
            s2.pop_back();
        }
        
        while(s1.length()) {
            int n1=s1.back()-'0';
            int sum = n1+c;
            string a=to_string(sum%10);
            c=sum/10;
            
            ret.insert(0,a);
            s1.pop_back();
        }
        
        if(1==c) {
            string a=to_string(1);
            ret.insert(0,a);
        }
        
        return ret;
    }
public:
    string addStrings(string num1, string num2) {
        string ret;
        
        if(num1.length()>=num2.length()) {
            ret=calculateSum(num1,num2);
        } else {
            ret= calculateSum(num2,num1);
        }
        
        return ret;
    }
};