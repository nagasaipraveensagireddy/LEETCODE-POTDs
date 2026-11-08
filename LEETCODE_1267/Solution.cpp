class Solution {
    struct Column{
        bool canCount = false;
        int cnt = 0;
    };
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, vector<int>>> rows(m);
        vector<Column> cols(n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    rows[i].first++;
                    rows[i].second.push_back(j);
                    if(cols[j].cnt++) cols[j].canCount = true;
                }
            }
        }
        int res = 0;
        for(auto& p : rows){
            if(p.first > 1){
                res += p.first;
                for(auto& c : p.second) cols[c].cnt--;
            }
        }
        for(auto& c : cols){
            if(c.canCount){
                res += c.cnt;
            }
        }
        return res;
    }
};