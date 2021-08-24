class Solution {
private:
    vector<int> initDp()
    {
        vector<int> ret;
        ret.push_back(1);
        
        return ret;
    }
    
    vector<int> calculateRow(vector<int> previous, int n)
    {
        vector<int> ret;
        
        for(int r=0; r<=n; r++)
        {
            if(r==0 || r==n)
            {
                ret.push_back(1);
                continue;
            }
            
            ret.push_back(previous[r-1]+previous[r]);
        }
        
        return ret;
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp;
    
        dp.push_back(initDp());//n=0
        
        for(int n=1; n<=rowIndex; n++)
        {
            dp.push_back(calculateRow(dp.back(),n));
        }
        
        return dp.back();
    }
};