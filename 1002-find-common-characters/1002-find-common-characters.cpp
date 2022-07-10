class Solution {
private:
    void calcultateCharacters(vector<int> &tempBuff, string word) {
        
        for(int i=0; i<word.length(); i++) {
            tempBuff[word[i]-'a']+=1;
        }
    }
    
    void compareBuff(vector<int> &buff, vector<int> tempBuff) {
        for(int i=0; i<buff.size(); i++) {
            if((buff[i]&&!tempBuff[i]) || (!buff[i]&&tempBuff[i])) {
                buff[i]=0;
            } else if(buff[i]&&tempBuff[i]) {
                buff[i]=min(buff[i],tempBuff[i]);
            } else {
                //do nothing
            }
        }
    }
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ret;
        vector<int> buff;
        vector<int> tempBuff;
        
        buff.assign(26,0);
        tempBuff.assign(26,0);
  
        calcultateCharacters(buff, words[0]);
        for(int i=1; i<words.size(); i++) {
            calcultateCharacters(tempBuff, words[i]);
            compareBuff(buff,tempBuff);
            fill(tempBuff.begin(), tempBuff.end(), 0);
        }
        
        for(int i=0; i<buff.size(); i++) {
            for(int j=0; j<buff[i];j++) {
                string temp;
                temp+='a'+i;
                ret.push_back(temp);
            }
        }
        
        return ret;
    }
};