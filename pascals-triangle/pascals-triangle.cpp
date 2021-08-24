class Solution {
private:
    vector<int> calculateRow(vector<int> previous,int n)
    {
        vector<int> ret;
        int r =0;
          
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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        int n=0;
        
        while(n<numRows)
        {
            if(n==0)
             {
                vector<int> row;
                row.push_back(1);
                ret.push_back(row);
            }
            else
            {
                vector<int> previous=ret.back();
                vector<int> row=calculateRow(previous,n);
                ret.push_back(row);
            }
            
            n++;
        }
        
        return ret;
    }
};