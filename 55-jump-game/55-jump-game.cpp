class Solution {
private:
    int myMin(int a, int b) {
        int ret=a;
        if(a>b)
            ret=b;
        
        return ret;
    }
    
    bool calculateDP(vector<int>& nums, vector<bool>& dp) {
        bool ret=false;
        for(int i=0; i<nums.size()-1; i++) {
            if(i+nums[i] >= nums.size()-1) {
                dp.push_back(true);
                ret=true;
            } else {
                dp.push_back(false);
            }
        }
        
        return ret;
    }
    
    bool calculateJump(vector<int>&nums, vector<bool>&dp) {
        bool ret=false;
        
        if(dp[0])
            return true;
        
        for(int i=nums.size()-2; i>=0;  i--) {
            int distance=  myMin(nums[i],nums.size() -i);
            
            if(dp[i])
                continue;
            
            for(int j=i+1; j<=i+distance; j++) {
                if(dp[j]) {
                    dp[i]=true;
                    break;
                }
            }
        }
        
        if(dp[0])
            ret=true;
        
        return ret;
    }
        
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp;
        bool ret=false;
        
        if(1==nums.size())
            return true;

        ret=calculateDP(nums,dp);
        
        if(ret==false)
            return ret;
        
        ret=calculateJump(nums,dp);
        
        return ret;
    }
};