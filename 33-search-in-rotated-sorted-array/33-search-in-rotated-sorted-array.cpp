class Solution {
private:
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        int low=left;
        int high=right;
        int mid=0;
        
        while(low<=high) {
            
            if(high-low==1) {
                if(target==nums[high]) {
                    return high;
                }
                else if(target==nums[low]) {
                    return low;
                }
                else {
                    return -1;
                }       
            }
            
            mid=(low+high)/2;
            
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid]>target) {
                high=mid-1;
            }
            else { //nums[mid]<target
                low=mid+1;
            }
        }
        
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int ret=0;
        int minNum=9999;
        int maxNum=-9999;
        int minIndex=-1;
        int maxIndex=-1;
        
        for(int i=0; i<nums.size(); i++) {
            if(maxNum<nums[i]) {
                maxNum=nums[i];
                maxIndex=i;
            }
            
            if(minNum>nums[i]) {
                minNum=nums[i];
                minIndex=i;
            }
        }
        
        if(target==maxNum)
            return maxIndex;
        
        if(target==minNum)
            return minIndex;
        
        if(target>maxNum || target <minNum)
            return -1;
        
        if(target>=nums[0]) {
            ret=binarySearch(nums,target,0,maxIndex);
        }
        else {
            ret=binarySearch(nums,target,minIndex, nums.size()-1);
        }
        
        return ret;
    }
};