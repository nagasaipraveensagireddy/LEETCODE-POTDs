
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
    string s, expected;
    int k;
    int testCase = 1;
    while(file >> s >> k >> expected){
        string res = obj.digitSum(s, k);

        cout << "Test case: " << testCase <<endl;

        if(res == expected){
            cout << "Status: PASS" <<endl;
        }
        else{
            cout << "Status: FAIL" <<endl;
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
