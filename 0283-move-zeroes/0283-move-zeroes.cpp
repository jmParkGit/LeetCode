class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nonZero;
        int zeroCnt=0;
        
        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            
            if(num) {
                nonZero.push_back(num);
            } else {
                zeroCnt++;
            }
        }
        
        nums.clear();
        
        for(int i=0; i<nonZero.size(); i++) {
            nums.push_back(nonZero[i]);
        }
        
        for(int i=0; i<zeroCnt; i++) {
            nums.push_back(0);
        }
        
    }
};