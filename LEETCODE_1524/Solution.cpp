class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();
        int oddSums = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            oddSums += (sum & 1);
        }
        long long evenSums = (n + 1) - oddSums;
        return (evenSums * oddSums) % MOD;
    }
};