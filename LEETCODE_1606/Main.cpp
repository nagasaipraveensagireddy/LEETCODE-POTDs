
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
    int k, n, expectedSize;
    int testCase = 1;

    while(file >> k >> n){
        vector<int> arrival(n), load(n);

        for(int i = 0; i < n; i++){
            if(!(file >> arrival[i])){
                cout<<"Invalid arrival input in test case :"<<testCase<<endl;
                return 1;
            }
        }

        for(int i = 0; i < n; i++){
            if(!(file >> load[i])){
                cout<<"Invalid load input in test case :"<<testCase<<endl;
                return 1;
            }
        }

        if(!(file >> expectedSize)){
            cout<<"Invalid expected data in test case :"<<testCase<<endl;
            return 1;
        }

        vector<int> expected(expectedSize);

        for(int i = 0; i < expectedSize; i++){
            if(!(file >> expected[i])){
                cout<<"Invalid expected data in test case :"<<testCase<<endl;
                return 1;
            }
        }

        vector<int> res = obj.busiestServers(k, arrival, load);

        cout << "Test case: " << testCase << endl;

        if(res == expected){
            cout << "Status: PASS" << endl;
        }
        else{
            cout << "Status: FAIL" << endl;
        }

        cout<<"Expected Result: ";
        for(auto& it : expected) cout<<it<<" ";

        cout<<"\nActual Result: ";
        for(auto& it : res) cout<<it<<" ";

        cout<<"\n______________________________\n";

        testCase++;
    }

    file.close();
    return 0;
}
