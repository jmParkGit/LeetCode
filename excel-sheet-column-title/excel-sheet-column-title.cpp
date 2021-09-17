class Solution {
private:
    const int DIGIT=26;
    
public:
    string convertToTitle(int columnNumber) {
        string ret;
        vector<int> stk;
        
        while(columnNumber > 0) {
            int remainder= (columnNumber-1)%DIGIT;
            stk.push_back(remainder);
            columnNumber=(columnNumber-1)/DIGIT;
        }
        
        while(!stk.empty()) {
            int n=stk.back();
            stk.pop_back();
            
            ret.push_back('A'+n);
        }
        
        return ret;
    }
};