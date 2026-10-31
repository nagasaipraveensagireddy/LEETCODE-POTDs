
#include<bits/stdc++.h>
using namespace std;
#include "Solution.cpp"

int main(){

    ifstream file("test_cases.txt");

    if(!file.is_open()){
        cout << "Failed to open the file." << endl;
        return 1;
    }

    Solution obj;

    int n, m, expected;
    int testCase = 1;

    while(file >> n >> m){

        vector<vector<int>> gird(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!(file >> gird[i][j])){
                    cout << "Invalid input int test case " << testCase << endl;
                    return 1;
                }
            }
        }
        if(!(file>> expected)){
            cout << "Invalid expected result in test case " << testCase << endl;
            return 1;
        }

        int res = obj.uniquePaths(gird);

        if(res == expected){
            cout << "Test case: " << testCase << endl;
            cout << "Status: PASS" << endl;
            cout << "Expected Result: " << expected << endl;
            cout << "Actual Result: " << res << endl;
        }
        else{
            cout << "Test case: " << testCase << endl;
            cout << "Status: FAIL" << endl;
            cout << "Expected Result: " << expected << endl;
            cout << "Actual Result: " << res << endl;
        }

        cout << "______________________________\n";

        testCase++;
    }

    file.close();

    return 0;
}
