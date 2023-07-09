class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ret=0;
        int y_length = grid.size();
        int x_length = grid[0].size();
        
        for(int y=0; y<y_length; y++){
            int currentlandCnt=0;
            int previousConnectdCnt=0;
            int middleVal=0;
            for(int x=0; x<x_length; x++) {
                
                if(x>=1 && (grid[y][x-1] != grid[y][x])) {
                    middleVal += 1;
                }
                
                if(grid[y][x]==1) {
                    currentlandCnt += 1;
                    
                    if((y>=1&&y<y_length) && grid[y-1][x]==1 ) {
                        previousConnectdCnt += 1;
                    }
                    
                    if(x==0 || x== x_length-1) {
                        middleVal += 1;
                    }
                    if(x_length == 1) {
                        middleVal += 1;
                    }
                        
                }
            }
            int val =  (currentlandCnt*2) - previousConnectdCnt*2;
            if(currentlandCnt) {
                val += (middleVal);
            }
            //cout << "y:" <<y <<" val:"<<val <<" currentlandCnt:"<<currentlandCnt <<" previousConnectdCnt:"<<previousConnectdCnt <<endl;
            ret += val;
        }
        return ret;   
    }
};