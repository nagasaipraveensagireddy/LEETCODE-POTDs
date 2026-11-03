class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = INT_MIN;
        for(auto& it : nums) maxi = max(maxi, it);
        int res = 0;
        for(auto& it : nums) res += maxi - it;
        return res;
    }
};