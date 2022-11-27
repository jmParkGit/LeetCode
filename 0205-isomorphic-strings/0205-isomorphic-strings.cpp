class Solution {
private:
    const static int MAX_INDEX_LENGTH=256;
    int sIndex[MAX_INDEX_LENGTH];
    int tIndex[MAX_INDEX_LENGTH];

    vector<int> changeToIndex(string s, int* arrIndex) {
        vector<int> ret;
        int index = 0;

        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            if(-1==arrIndex[ch]) {
                arrIndex[ch] = index++;
                ret.push_back(arrIndex[ch]);
            } else {
                ret.push_back(arrIndex[ch]);
            }
        }
 
        return ret;
    }

public:
    Solution () {
        for(int i=0; i<MAX_INDEX_LENGTH; i++) {
            sIndex[i] = -1;
            tIndex[i] = -1;
        }
    }

    bool isIsomorphic(string s, string t) {
        bool ret = true;
        int index = 0;
        vector<int> myS = changeToIndex(s,sIndex);
        vector<int> myT = changeToIndex(t,tIndex);

        for(int i=0; i<myS.size(); i++) {

            if(myS[i] != myT[i]) {
                ret = false;
                break;
            }
        }

        return ret;
    }
};