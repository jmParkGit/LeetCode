class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret=0;
        map<int, bool> m;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            m.insert({nums[i],true});
        }
        
        for(int i=0; i<=n; i++) {
            if(m.find(i) == m.end()) {
                ret = i;
                break;
            }
        }
        
        return ret;
    }
};