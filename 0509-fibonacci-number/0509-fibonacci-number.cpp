class Solution {
private:
    int dp[30+1] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040};
    
    void preprocessing() {
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=2; i<=30; i++) {
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        for(int i=0; i<=30; i++) {
            cout<<dp[i]<<",";
        }
        cout<<endl;
        cout << dp[30] << endl;
    }
public:
    int fib(int n) {
        //preprocessing();
        return dp[n];
    }
};