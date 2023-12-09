class Solution {
public:
    void reverseString(vector<char>& s) {
        int length = s.size();
        
        for(int i=0; i<length/2; i++) {
            int left = i;
            int right = length-1-i;
            char temp=0;
            
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
        }
    }
};