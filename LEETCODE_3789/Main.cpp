
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
    int cost1, cost2, costBoth, need1, need2, expected;
    int testCase = 1;

    while(file >> cost1 >> cost2 >> costBoth >> need1 >> need2 >> expected){
        if(!(file >> expected)){
            cout<<"Invalid expected data in test case :"<<testCase<<endl;
            return 1;
        }
        int res = obj.minimumCost(cost1, cost2, costBoth, need1, need2);

        cout << "Test case: " << testCase << endl;

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
