
#include <bits/stdc++.h>
using namespace std;
#include "Solution.cpp"

bool isValidGrid(vector<string>& grid, int m, int n) {
    if (grid.size() != m) return false;

    for (string& row : grid) {
        if (row.size() != n) return false;

        for (char c : row) {
            if (c != '.' && c != '#') return false;
        }
    }

    if (grid[0][0] != '.' || grid[m - 1][n - 1] != '.') {
        return false;
    }
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                dp[i][j] = 0;
                continue;
            }

            if (i == 0 && j == 0) continue;

            int fromTop = (i > 0) ? dp[i - 1][j] : 0;
            int fromLeft = (j > 0) ? dp[i][j - 1] : 0;

            dp[i][j] = min(2, fromTop + fromLeft);
        }
    }

    return dp[m - 1][n - 1] == 1;
}

int main() {
    ifstream file("test_cases.txt");

    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    Solution obj;
    int m, n;
    int testCase = 1;

    while (file >> m >> n) {

        vector<string> res = obj.createGrid(m, n);

        bool valid = isValidGrid(res, m, n);

        cout << "Test case: " << testCase << endl;

        if (valid) {
            cout << "Status: PASS" << endl;
            cout << "Returned grid:" << endl;
            for (const auto& row : res) {
                cout << row << endl;
            }
        } else {
            cout << "Status: FAIL" << endl;
            cout << "Returned result:" << endl;
            for (const auto& row : res) {
                cout << row << endl;
            }
        }

        cout << "______________________________" << endl;
        testCase++;
    }

    file.close();
    return 0;
}
