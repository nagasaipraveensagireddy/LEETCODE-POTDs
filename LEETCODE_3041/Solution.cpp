class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 1;
        //element : max achievable length till that element
        unordered_map<int, int> dp;
        for(auto& it : nums){
            int unchanged = 1, increased = 1;
            if(dp.find(it - 1) != dp.end()) unchanged = dp[it - 1] + 1;
            if(dp.find(it) != dp.end()) increased = dp[it] + 1;
            dp[it] = max(dp[it], unchanged);
            dp[it + 1] = max(dp[it + 1], increased);
            res = max(res, max(dp[it], dp[it + 1]));
        }
        return res;
    }
};