class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        long long sum = 0;
        for(auto& it : nums){
            mini = min(mini, it);
            sum += it;
        }
        return sum - (mini * n);
    }
};