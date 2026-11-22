
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
    bool expected;
    int testCase = 1;

    while(file >> s >> expected){
        bool res = obj.checkString(s);
        cout << "Test Case " << testCase << "s\n";
        if(res == expected){
            cout << "Status: PASS" << endl;
        }
        else{
            cout << "Status: FAIL" << endl;
        }

        cout<<"Expected Result: ";
        cout<<expected<<" ";

        cout<<"\nActual Result: ";
        cout<<res<<" ";

        cout<<"\n______________________________\n";

        testCase++;
    }

    file.close();
    return 0;
}
