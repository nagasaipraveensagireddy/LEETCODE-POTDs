
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
    string s;
    int n;;
    int testCase = 1;

    while(file >> n >> s){
        vector<int> parent(n);
        for(int i = 0; i < n; i++){
            if(!(file >> parent[i])){
                cout << "Invalid array input in test case :" << testCase << endl;
                return 1;
            }
        }
        vector<int> expected(n);
        for(int i = 0; i < n; i++){
            if(!(file >> expected[i])){
                cout << "Invalid expected data in test case :" << testCase << endl;
                return 1;
            }
        }
        vector<int> res = obj.findSubtreeSizes(parent, s);
        cout << "Test Case " << testCase << "s\n";
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
