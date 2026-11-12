class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 1, up = 1, down = 1;
        for(int i = 1; i < n; i++){
            up = nums[i] > nums[i - 1] ? up + 1 : 1;
            down = nums[i] < nums[i - 1] ? down + 1 : 1;
            res = max({res, up, down});
        }
        return res;
    }
};