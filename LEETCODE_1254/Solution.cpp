#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int m, int n, int row, int col, vector<int>& drow, 
             vector<int>& dcol, vector<vector<int>>& vis, bool& onBoundary){
        vis[row][col] = 1;
        if(!row || row == m - 1 || !col || col == n - 1)  onBoundary = true;
        for(int i = 0; i < 4; i++){
            int nr = row + drow[i];
            int nc = col + dcol[i];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && !grid[nr][nc] && !vis[nr][nc]){
                dfs(grid, m, n, nr, nc, drow, dcol, vis, onBoundary);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j] && !vis[i][j]){
                    bool onBoundary = false;
                    dfs(grid, m, n, i, j, drow, dcol, vis, onBoundary);
                    if(!onBoundary) cnt++;
                }
            }
        }
        return cnt;
    }
};