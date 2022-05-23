class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool> m;
        bool ret=false;
        
        if(!nums.size())
            return ret;
        
        m.insert({nums[0],true});
            
        for(int i=1; i<nums.size(); i++) {
            if(m.find(nums[i])!=m.end()) {
                ret = true;
                break;
            } else {
                m.insert({nums[i],true});
            }
        }
        
        return ret;
    }
};