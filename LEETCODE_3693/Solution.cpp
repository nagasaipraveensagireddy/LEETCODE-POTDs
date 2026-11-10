class Solution {
public:
    int solve(int i, vector<int>& costs, int n, vector<int>& dp){
        if(!i) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        if(i - 1 >= 0) ans = min(ans, solve(i - 1, costs, n, dp) + costs[i] + 1);
        if(i - 2 >= 0) ans = min(ans, solve(i - 2, costs, n, dp) + costs[i] + 4);
        if(i - 3 >= 0) ans = min(ans, solve(i - 3, costs, n, dp) + costs[i] + 9);
        return dp[i] = ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(), 0);
        vector<int> dp(n + 1, -1);
        return solve(n, costs, n, dp);
    }
};