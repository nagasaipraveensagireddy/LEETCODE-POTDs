class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;
        vector<int> factorFreq(n + 1, 0);
        for(auto& item :items){
            int factor = item[0];
            int price = item[1];
            factorFreq[factor]++;
            minPrice = min(minPrice, price);
        }
        vector<int> pairs(n + 1, -1);
        vector<pair<int, int>> deals;
        for(auto& item :items){
            int factor = item[0];
            int price = item[1];
            if(price < 2 * minPrice) deals.push_back({price, factor});
        }
        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>, 
                       greater<pair<int, int>>> minHeap(deals.begin(), deals.end());
        int res = 0;
        while(!minHeap.empty() && minHeap.top().first <= budget){
            auto[price, factor] = minHeap.top();
            minHeap.pop();
            if(pairs[factor] == -1){
                pairs[factor] = 0;
                for(int multiple = factor; multiple <= n; multiple += factor){
                pairs[factor] += factorFreq[multiple];
                }
            }
            int possiblePairs = min(pairs[factor] - 1, budget / price);
            res += 2 * possiblePairs;
            budget -= possiblePairs * price;
        }
        res += budget / minPrice;
        return res;
    }
};