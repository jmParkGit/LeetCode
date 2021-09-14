class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0;
        int minPrices=9999;
        
        for(int i=0; i<prices.size(); i++) {
            if(minPrices > prices[i])
                minPrices=prices[i];
            
            if(maxP<prices[i]-minPrices) {
                maxP=prices[i]-minPrices;
            }
        }
        
        return maxP;
    }
};