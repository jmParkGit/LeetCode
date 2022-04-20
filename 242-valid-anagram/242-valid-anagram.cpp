class Solution {
private:
    const static int ALPHABET=26;
public:
    bool isAnagram(string s, string t) {
        int buffer_s[ALPHABET]={0,};
        int buffer_t[ALPHABET]={0,};
        bool ret=false;
        
        if(s.length() != t.length())
            return ret;
        
        for(int i=0; i<s.length(); i++) {
            buffer_s[s[i]-'a']++;
            buffer_t[t[i]-'a']++;
        }
        
        for(int i=0; i<ALPHABET; i++) {
            if(buffer_s[i] != buffer_t[i])
                return ret;
        }
        
        ret = true;
        return ret;
    }
};