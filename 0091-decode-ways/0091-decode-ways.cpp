class Solution {
public:
    int numDecodings(string s) {
        int ret =0;
        int dp[100+1]={0,};

        if('0' != s[0]) {
            dp[0]=dp[1]=1;
        }

        for(int i=1; i<s.length(); i++) {
            
            if('0' != s[i]) {
                dp[i+1] = dp[i];
            }
            
            int n = stoi(s.substr(i-1,2));
            if(10<=n && n<=26) {
                cout<<"n: "<< n << endl;
                dp[i+1]+=dp[i-1];
            }
        }

        return dp[s.length()];
    }

};