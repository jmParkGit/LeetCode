class Solution {
private:
    static const int MAX_M = 100;
    static const int MAX_N = 100;
    int arr[MAX_M][MAX_N];
public:
    int uniquePaths(int m, int n) {
        
        for(int y=0; y<m; y++) {
            arr[y][0] = 1;
        }
        
        for(int x=0; x<n; x++) {
            arr[0][x] = 1;
        }
        
        for(int y=1; y<m; y++) {
            for(int x=1; x<n; x++) {
                arr[y][x] = arr[y][x-1]+arr[y-1][x];
            }
        }
        
        return arr[m-1][n-1];
    }
};