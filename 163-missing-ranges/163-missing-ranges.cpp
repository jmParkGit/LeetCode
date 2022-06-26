class Solution {
private:
    string makeStr(int a, int b) {
        string ret;
        
        if(a==b) {
            ret+=to_string(a);
        } else {
            ret+=to_string(a);
            ret+="->";
            ret+=to_string(b);
        }
    
        return ret;
    }
    
void calculateRanges(vector<string>& output, vector<int>& nums) {
    int current=0xffff;
    int next=0xffff;
    
    for(int i=0;i<nums.size()-1; i++) {
        current=nums[i];
        next=nums[i+1];
        
        if(current+1 == next)
            continue;
        
        string temp = makeStr(current+1, next-1);
        output.push_back(temp);
    }
}
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        
        
        if(!nums.size()) {
            string temp=makeStr(lower, upper);
            ret.push_back(temp);
            return ret;
        }
        
        if(lower < nums[0]) {
            string temp=makeStr(lower,nums[0]-1);
            ret.push_back(temp);
        }
        
        if(nums.size()>=1) {
            calculateRanges(ret,nums);
        }
        
        if(nums[nums.size()-1]<upper) {
            string temp=makeStr(nums[nums.size()-1]+1, upper);
            ret.push_back(temp);
        }
        
        return ret;
    }
};