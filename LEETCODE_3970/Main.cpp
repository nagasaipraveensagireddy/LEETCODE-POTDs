
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

    int n, m, k, expected;
    string labels;
    int testCase = 1;

    while(file >> n >> m){

        // Read edges
        vector<vector<int>> edges(m);

        for(int i = 0; i < m; i++){
            int u, v, w;
            file >> u >> v >> w;

            edges[i] = {u, v, w};
        }

        // Read labels, k and expected result
        file >> labels >> k >> expected;

        // Execute the function
        int res = obj.shortestPath(n, edges, labels, k);

        // Compare actual and expected results
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
