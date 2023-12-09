class Solution {
private:
    unsigned int r['z'] = {0,};
    unsigned int m['z'] = {0,};
    
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool ret = true;
        
        for(int i=0; i<ransomNote.length(); i++) {
            r[ransomNote[i]-'a']++;
        }
        
        for(int i=0; i<magazine.length(); i++) {
            m[magazine[i]-'a']++;
        }
        
        for(int i=0; i<'z'; i++) {
            if(r[i]>m[i]) {
                ret = false;
                break;
            }
        }
        
        return ret;
    }
};