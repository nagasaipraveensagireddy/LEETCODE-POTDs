class Solution {
public:
    int m, n;
    long long dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i == m || j < 0 || j == n || !grid[i][j]) return 0;
        int val = grid[i][j];
        grid[i][j] = 0;
        return val + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + 
                     dfs(grid, i + 1, j) + dfs(grid, i, j - 1);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int res = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    long long val = dfs(grid, i, j);
                    res += !(val % k);
                }
            }
        }
        return res;
    }
};