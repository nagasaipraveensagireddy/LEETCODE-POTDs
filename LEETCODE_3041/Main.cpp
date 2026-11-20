
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
    int n, expected;
    int testCase = 1;

    while(file >> n >> expected){
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            if(!(file >> nums[i])){
                cout << "Invalid array input in test case :" << testCase << endl;
                return 1;
            }
        }
        int res = obj.maxSelectedElements(nums);
        cout << "Test Case " << testCase << "\n";
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
