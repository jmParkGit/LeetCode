class Solution {
private:
    static const int DIRECTION=4;
    const int dY[DIRECTION]={-1,0,1,0};
    const int dX[DIRECTION]={0,1,0,-1};
    
    int Y;
    int X;
    
    bool checkWord(vector<vector<char>>& board, string word, int y, int x, int index) {
        bool ret=false;
        
        if(index==word.length())
            return true;
        
        if(y>=Y || y<0 || x>=X || x<0)
            return false;
        
        if(board[y][x]==0)
            return false;
        
        if(word[index]!=board[y][x])
            return false;
        
        board[y][x]=0;
        
        for(int i=0; i<DIRECTION; i++) {
            int currentY=y+dY[i];
            int currentX=x+dX[i];
            
            if(checkWord(board,word,currentY,currentX,index+1)) {
                ret=true;
                break;
            } 
        }
        
        board[y][x]=word[index];
        
        return ret;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ret=false;
        Y=board.size();
        X=board[0].size();
        
        for(int y=0; y<Y; y++) {
            for(int x=0; x<X;x++) {
                if(board[y][x]==word[0]) {
                    if(checkWord(board,word,y,x,0))
                        return true;
                }
            }
        }
        
        return ret;
    }
};