class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> grid(m, vector<char>(n, '#'));
        for(int i = 0; i < m; i++){
            grid[i][0] = '.';
        }
        for(int j = 0; j < n; j++){
            grid[m - 1][j] = '.';
        }
        vector<string> res;
        for(int i = 0; i < m; i++){
            string s = "";
            for(int j = 0; j < n; j++){
                s += grid[i][j];
            }
            res.push_back(s);
        }
        return res;
    }
};