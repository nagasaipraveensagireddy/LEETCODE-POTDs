class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int maxFactor = 0, minPrice = INT_MAX;
        for(auto& item : items){
            maxFactor = max(maxFactor, item[0]);
            minPrice = min(minPrice, item[1]);
        }
        vector<int> factorFreq(maxFactor + 1, 0);
        for(auto& item : items){
            factorFreq[item[0]]++;
        }
        vector<int> gain(maxFactor + 1, 0);
        for(int factor = 1; factor <= maxFactor; factor++){
            for(int multiple = factor; multiple <= maxFactor; multiple += factor){
                gain[factor] += factorFreq[multiple];
            }
        }
        vector<int> dp(budget + 1, 0);
        for(int money = 0; money <= budget; money++){
            dp[money] = money / minPrice;
        }
        for(auto& item : items){
            int factor = item[0];
            int price = item[1];
            if(gain[factor] <= price / minPrice) continue;
            for(int money = budget ; money >= price; money--){
                dp[money] = max(dp[money], dp[money - price] + gain[factor]);
            }
        }
        return dp[budget];
    }
};