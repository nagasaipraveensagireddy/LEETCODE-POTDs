class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> down(m, vector<int>(n, 0));
        vector<vector<int>> right(m, vector<int>(n, 0));
        down[0][0] = 1;
        right[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!i && !j) continue;
                int fromAbove = 0;
                int fromLeft = 0;
                if(i) fromAbove = down[i - 1][j];
                if(j) fromLeft = right[i][j - 1];
                if(grid[i][j]){
                    down[i][j] = fromLeft;
                    right[i][j] = fromAbove;
                }
                else{
                    int total = (fromAbove + fromLeft) % MOD;
                    down[i][j] = total;
                    right[i][j] = total;
                }
            }
        }
        return down[m - 1][n - 1];
    }
};