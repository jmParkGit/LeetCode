class Solution {
private:
    
    int toMaxDecimal(int n) {
        int bin=0;
        
        for(int i=0; i<n; i++) {
            bin=(bin<<1)|1;
        }
        
        return bin;
    }
    
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        int maxDecimal=toMaxDecimal(n);
    
        for(int i=0; i<=maxDecimal; i++) {
            int gray=i^(i>>1);
            ret.push_back(gray);
        }
        
        return ret;
    }
};