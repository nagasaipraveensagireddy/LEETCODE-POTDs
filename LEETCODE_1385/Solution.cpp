class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for(auto& it1 : arr1){
            int canBeCounted = 1;
            for(auto& it2 : arr2){
                if(abs(it1 - it2) <= d){
                    canBeCounted = 0;
                    break;
                }
            }
            cnt += canBeCounted;
        }
        return cnt;
    }
};