#include<bits/stdc++.h>
using namespace std;
#include "Solution.cpp"

int main(){
    ifstream file("test_cases.txt");

    if(!file.is_open()){
        cout<<"Failed to open test_cases.txt";
        return 1;
    }
    Solution obj;
    int m, n, expected;
    int testCase = 1;
    while(file >> m >> n){
        vector<vector<int>> grid(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!(file >> grid[i][j])){
                    cout<<"Invaild grid input in test case :"<<testCase<<endl;
                    return 1;
                }
            }
        }
        if(!(file >> expected)){
            cout<<"Invaild expected data in test case :"<<testCase<<endl;
            return 1;
        }
        int res = obj.countServers(grid);
        if(res == expected){
            cout << "Test case: " << testCase << endl;
            cout << "Status: PASS" << endl;
            cout<<"Expected Result:"<<expected<<endl;
            cout<<"Actual Result: "<<res<<endl;
            cout<<"______________________________\n";
        }
        else{
            cout << "Test case: " << testCase << endl;
            cout << "Status: FAIL" << endl;
            cout<<"Expected Result:"<<expected<<endl;
            cout<<"Actual Result: "<<res<<endl;
            cout<<"______________________________\n";
        }
        testCase++;
    }

}
