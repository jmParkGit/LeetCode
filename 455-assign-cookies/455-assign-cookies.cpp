class Solution {
private:
    int findMaxS(int g, vector<int>& s) {
        for(int j=s.size()-1; j>=0; j--) {
                if(g<=s[j]) {
                    s[j]-=g;
                    return 1;
                }
            }
        return 0;
    }
    
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ret=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        for(int i = g.size()-1; i>=0; i--) {
            ret+=findMaxS(g[i], s);
        }
        
        return ret;
    }
};