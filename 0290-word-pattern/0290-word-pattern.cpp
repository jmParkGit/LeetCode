class Solution {
private:
    vector<int> patternList;
    map<int,string> m;
    map<string,int> m2;
    const string seperator = " ";
    
    bool isPatternCorrect(int index, string result) {
        bool ret=true;
        
        if(index>=patternList.size()) {
            return false;
        }
        
        if(m.find(patternList[index]) !=m.end()) {
            if (result.compare(m.find(patternList[index])->second)==0 ) {
                //do nothing
            } else {
                ret = false;
            }
        } else {
            m.insert({patternList[index], result});
        }
        
        if(m2.find(result) !=m2.end()) {
            if(patternList[index] != m2.find(result)->second) {
                ret = false;
            }
        } else {
            m2.insert({result, patternList[index]});
        }
        
        return ret;
    }
    
public:
    bool wordPattern(string pattern, string s) {
        bool ret=true;
        int len = 0;
        int pos=0;
        int currentPos=0;
        int index = 0;
        
        for(int i=0; i<pattern.size(); i++) {
            patternList.push_back(pattern[i]-'a');
        }
        
        while((pos = s.find(seperator,currentPos)) != string::npos) {
            len = pos - currentPos;
            string result = s.substr(currentPos,len);
            
            if(false == (ret=isPatternCorrect(index, result))) {
                break;
            }
            
            currentPos = pos+1;
            index+=1;
        }
        
        //last word
        string result = s.substr(currentPos);
        ret = isPatternCorrect(index, result);
        index+=1;
        
        if(index != patternList.size()) {
            ret = false;
        }
            
        return ret;
    }
};