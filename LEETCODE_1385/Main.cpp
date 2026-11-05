
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

    int m, n, d, expected;
    int testCase = 1;

    while(file >> m >> n >> d){

        vector<int> nums1(n);
        vector<int> nums2(m);

        for(int i = 0; i < m; i++){
            if(!(file >> nums1[i])){
                cout << "Invalid array input in test case " << testCase << endl;
                return 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(!(file >> nums2[i])){
                cout << "Invalid array input in test case " << testCase << endl;
                return 1;
            }
        }
        if(!(file>> expected)){
            cout << "Invalid expected result in test case " << testCase << endl;
            return 1;
        }
        int res = obj.findTheDistanceValue(nums1, nums2, d);

        if(res == expected){
            cout << "Test case: " << testCase << endl;
            cout << "Status: PASS" << endl;
            cout << "Expected Result: " << expected << endl;
            cout << "Actual Result: " << res << endl;
        }
        else{
            cout << "Test case: " << testCase << endl;
            cout << "Status: FAIL" << endl;
            cout << "Expected Result: " << expected << endl;
            cout << "Actual Result: " << res << endl;
        }

        cout << "______________________________\n";

        testCase++;
    }

    file.close();

    return 0;
}
