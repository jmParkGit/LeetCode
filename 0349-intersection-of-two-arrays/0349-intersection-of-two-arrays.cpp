class Solution {    
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        vector<int> buffer(1001,0);
        
        for(int i=0; i<nums1.size(); i++) {
            int val1= nums1[i];
            
            if(!buffer[val1]) {
                buffer[val1] = 1;
            }
        }
        
        for(int i=0; i<nums2.size(); i++) {
            int val2= nums2[i];
            
            if(!buffer[val2]) {
                continue;
            } else {
                buffer[val2] +=1;
            }
        }
        
        for(int i=0; i<buffer.size(); i++) {
            if(1<buffer[i]) {
                ret.push_back(i);
            }
        }
        
        return ret;
    }
};