class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret=0;
        map<int,int> m;
        int maxKey=nums[0];
        int maxVal=1;
        
        for(int i=0; i<nums.size(); i++) {
            map<int,int>::iterator iter = m.find(nums[i]);
            
            if(iter!=m.end()) {
                
                iter->second++;
                
                if(maxVal < (iter->second)) {
                    maxKey=nums[i];
                    maxVal=iter->second;
                }
            }
            else {
                m.insert({nums[i],1});
            }
        }
        
        return maxKey;
    }
};