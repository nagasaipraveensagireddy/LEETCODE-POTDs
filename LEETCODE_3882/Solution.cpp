class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<bitset<1024>> dp(n);
        dp[0][0] = 1;
        for(auto& row : grid){
            for(int j = 0; j < n; j++){
                auto reach = j ? dp[j] | dp[j - 1] : dp[j];
                dp[j].reset();
                for(int i = 0; i < 1024; i++){
                    if(reach[i]) dp[j][i ^ row[j]] = 1;
                }
            }
        }
        int res = 0;
        while(!dp[n - 1][res]) res++;
        return res;
    }
};