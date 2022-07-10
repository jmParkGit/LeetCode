// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1;
        int right=n;
        int mid=0;
        
        while(left<right) {
            mid=left+(right-left)/2;
            if(true==isBadVersion(mid)) {
                right=mid;
            } else {
                left=mid+1;
            }
            
            mid=left+(right-left)/2;
        }
        
        return left;
    }
};