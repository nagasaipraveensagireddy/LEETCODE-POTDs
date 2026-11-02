class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = nums.size()/2;
        int median = nums[mid];
        int res = 0;
        for(auto& it : nums) res += abs(it - median);
        return res;
    }
};