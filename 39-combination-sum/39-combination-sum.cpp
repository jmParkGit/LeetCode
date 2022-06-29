class Solution {
private:
    vector<vector<int>> answer;
    vector<int> buf;
    
    bool calculateList(vector<int>& candidates, int target, int n, int sum) {
        bool ret = false;
        buf.push_back(candidates[n]);
        sum+=candidates[n];
        
        if(target == sum) {
            answer.push_back(buf);
            ret=true;
        } else if (target < sum) {
            ret=false;
        } else {
            for(int i=n; i<candidates.size(); i++) {
                if(false==calculateList(candidates, target, i, sum)) {
                    break;
                }
            }
            
            ret=true;
        }
        
        buf.pop_back();
        return ret;
    }
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        for(int i=0; i<candidates.size(); i++) {
            calculateList(candidates, target, i, 0);
        }
        
        return answer;
    }
};