class Solution {
private:
    string parseInputString(string s)
    {
        string ret="";
        
        for(int i=0;i <s.length(); i++)
        {
            char c=s[i];
            
            if(!isalnum(c))
                continue;
            
            if('a'<=c && c<='z')
                ret.push_back(c);
            else if('A'<=c && c<='Z')
                ret.push_back('a'+(c-'A'));
            else if('0'<= c&& c<='9')
                ret.push_back(c);
            //else
                //do nothing
        }
        
        return ret;
    }
    
    bool checkPalindrome(string s)
    {
        int length=s.length();
        bool ret=true;
        
        for(int i=0; i<length/2;i++)
        {
            if(s[i] != s[(length-1)-i])
            {
                ret=false;
                break;
            }
        }
        
        return ret;
    }
    
public:
    bool isPalindrome(string s) {
        bool ret=true;
        string parsing = parseInputString(s);
        
        if(parsing.length() == 1)
            return ret;
        
        ret=checkPalindrome(parsing);
        
        return ret;
    }
};