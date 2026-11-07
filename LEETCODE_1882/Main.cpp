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

    int n, m;   
    int testCase = 1;

    while(file >> n >>m){

        vector<int> servers(n);
        vector<int> tasks(m);

        for(int i = 0; i < n; i++){
            if(!(file >> servers[i])){
                cout << "Invalid servers input in test case " << testCase << endl;
                return 1;
            }
        }
        for(int i = 0; i < m; i++){
            if(!(file >> tasks[i])){
                cout << "Invalid tasks input in test case " << testCase << endl;
                return 1;
            }
        }

        vector<int> expected(m);
        for(int i = 0; i < m; i++){
            if(!(file >> expected[i])){
                cout << "Invalid expected data in test case " << testCase << endl;
                return 1;
            }
        }

        vector<int> res = obj.assignTasks(servers, tasks);

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