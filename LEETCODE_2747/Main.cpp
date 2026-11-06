#include <bits/stdc++.h>
using namespace std;
#include "Solution.cpp"

int main(){

    ifstream file("test_cases.txt");

    if(!file.is_open()){
        cout << "Failed to open the file." << endl;
        return 1;
    }

    Solution obj;

    int n, logsSize, x, queriesSize;
    int testCase = 1;

    while(file >> n >> logsSize >> x >> queriesSize){

        vector<vector<int>> logs(logsSize, vector<int>(2));
        vector<int> queries(queriesSize);
        vector<int> expected(queriesSize);

        for(int i = 0; i < logsSize; i++){
            if(!(file >> logs[i][0] >> logs[i][1])){
                cout << "Invalid logs input in test case " << testCase << endl;
                return 1;
            }
        }

        for(int i = 0; i < queriesSize; i++){
            if(!(file >> queries[i])){
                cout << "Invalid query input in test case " << testCase << endl;
                return 1;
            }
        }

        for(int i = 0; i < queriesSize; i++){
            if(!(file >> expected[i])){
                cout << "Invalid expected result in test case " << testCase << endl;
                return 1;
            }
        }

        vector<int> res = obj.countServers(n, logs, x, queries);

        if(res == expected){
            cout << "Test case: " << testCase << endl;
            cout << "Status: PASS" << endl;

            cout << "Expected Result: ";
            for(auto& it : expected) cout << it << " ";
            cout << endl;

            cout << "Actual Result: ";
            for(auto& it : res) cout << it << " ";
            cout << endl;
        }
        else{
            cout << "Test case: " << testCase << endl;
            cout << "Status: FAIL" << endl;

            cout << "Expected Result: ";
            for(auto& it : expected) cout << it << " ";
            cout << endl;

            cout << "Actual Result: ";
            for(auto& it : res) cout << it << " ";
            cout << endl;
        }

        cout << "________________________________________\n";

        testCase++;
    }

    file.close();

    return 0;
}