class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int,int> um;
        vector<int> stk;
        
        stk.push_back(nums2[0]);
        
        for(int i=1; i<nums2.size(); i++) {
            if(stk.back() >= nums2[i]) {
                stk.push_back(nums2[i]);
                continue;
            }
            
            while(!stk.empty()) {
                if(stk.back() >= nums2[i]) {
                    break;
                }
                
                um.insert(make_pair(stk.back(), nums2[i]));
                stk.pop_back();
            }
            
            stk.push_back(nums2[i]);
        }
        
        for(int i=0; i<nums1.size(); i++) {
            if(um.end() != um.find(nums1[i])) {
                ret.push_back(um.find(nums1[i])->second);
            } else {
                ret.push_back(-1);
            }
        }
        
        return ret;
    }
};