class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool ret = false;
        unordered_map<int, int> um;

        for(int i=0; i<nums.size(); i++) {
            if(1<=um.count(nums[i])) {
                int previous = um[nums[i]];

                if((i-previous)<=k) {
                    ret = true;
                    break;
                }
                else {
                    um[nums[i]] = i;
                }
            } else {
                um.insert({nums[i],i});
            }
            
        }
        
        return ret;
    }
};