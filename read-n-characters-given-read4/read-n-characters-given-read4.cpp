/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ret=0;
        
        while(ret<n) {
            char buf4[4]={0,};
            int inputCnt= read4(buf4);
            
            if(inputCnt == 0)
                break;
            
            for(int i=0; i<inputCnt; i++) {
                if(ret>=n)
                    return ret;
                
                buf[ret++]=buf4[i];
            }
        }
        
        return ret;
    }
};