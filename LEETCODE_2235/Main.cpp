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
    int num1 ,num2 , expected;
    int testCase = 1;

    while(file >> num1 >> num2 >> expected){
        int res = obj.sum(num1, num2);
        if(res == expected){
            cout<<"Test case: "<<testCase<<endl;
            cout<<"Status: PASS"<<endl;
            cout<<"Expected Result:"<<expected<<endl;
            cout<<"Actual Result: "<<res<<endl;
            cout<<"______________________________\n";
        }
        else{
            cout<<"Test case: "<<testCase<<endl;
            cout<<"Status: FAIL"<<endl;
            cout<<"Expected Result:"<<expected<<endl;
            cout<<"Actual Result: "<<res<<endl;
            cout<<"______________________________\n";
        }
        testCase++;
    }
    file.close();
    return 0;
}