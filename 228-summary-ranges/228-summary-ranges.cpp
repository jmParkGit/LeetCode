#include <stdlib.h>

class Solution {
private:
    string makeStr(int a, int b) {
        string ret;
        ret += to_string(a);
        if(a==b) {
            //do nothing
        } else {              
            ret.push_back('-');
            ret.push_back('>');
                              
            ret += to_string(b);
        }
        
        return ret;
    }
    
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        vector<vector<int>> buf;
        int current=0xffff;
        int previous=0xffff;
        int left=0xffff;
        
        if(0==nums.size())
            return ret;
        
        if(1==nums.size()){
            string temp = makeStr(nums[0],nums[0]);
            ret.push_back(temp);
            return ret;
        }
        
        previous=nums[0];
        left=nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(previous+1 == nums[i]) {
                previous = nums[i];
                continue;
            }
            
            string temp = makeStr(left,previous);
            ret.push_back(temp);
            previous=nums[i];
            left=nums[i];
        }
        
        string temp = makeStr(left,previous);
        ret.push_back(temp);
        
        return ret;
    }
};