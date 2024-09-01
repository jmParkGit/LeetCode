class Solution {
public:
    string toLowerCase(string s) {
        string ret;
        
        for(int i=0; i<s.length(); i++) {
            if(('A'<=s[i]) && (s[i]<='Z')) {
                ret.push_back(s[i]-'A'+'a');
            } else {
                ret.push_back(s[i]);
            }
        }
        
        return ret;
    }
};