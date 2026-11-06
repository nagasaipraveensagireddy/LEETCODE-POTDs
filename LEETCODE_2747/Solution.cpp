class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        logs.push_back({0, INT_MAX});
        vector<int> order(queries.size());
        for(int i = 0; i < order.size(); i++) order[i] = i;
        sort(order.begin(), order.end(), [&](int a, int b){
            return queries[a] < queries[b];
        });
        vector<int> cnt(n + 1);
        vector<int> res(queries.size());
        int busy = 0, high = 0, low = 0;
        for(int& i : order){
            int q = queries[i];
            while(logs[high][1] <= q){
                int server = logs[high][0];
                if(!cnt[server]) busy++;
                cnt[server]++;
                high++;
            }
            while(logs[low][1] < q - x){
                int server = logs[low][0];
                cnt[server]--;
                if(!cnt[server]) busy--;
                low++;
            }
            res[i] = n - busy;
        }
        return res;
    }
};