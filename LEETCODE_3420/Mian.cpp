
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
    int n, k;
    long long expected;
    int testCase = 1;

    while(file >> n >> k){
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            if(!(file >> nums[i])){
                cout<<"Invalid array input in test case :"<<testCase<<endl;
                return 1;
            }
        }
        if(!(file >> expected)){
            cout<<"Invalid expected data in test case :"<<testCase<<endl;
            return 1;
        }
        long long res = obj.countNonDecreasingSubarrays(nums, k);

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
