class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> plateauStarts(n);
        int head = n, tail = n, right = n - 1;
        long long res = 0, water = 0;
        for(int l = n - 1; l >= 0; l--){
            int curr = nums[l];
            while(head < tail && nums[plateauStarts[head]] <= curr){
                int start = plateauStarts[head++];
                int end = (head < tail) ? plateauStarts[head] : right + 1;
                water += 1LL * (curr - nums[start]) * (end - start);
            }
            plateauStarts[--head] = l;
            while(water > k){
                int lastPlateau = plateauStarts[tail - 1];
                water -= (nums[lastPlateau] - nums[right]);
                if(lastPlateau == right) tail--;
                right--;
            }
            res += right - l + 1;
        }
        return res;
    }
};