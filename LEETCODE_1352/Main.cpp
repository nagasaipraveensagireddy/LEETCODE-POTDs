#include <bits/stdc++.h>
using namespace std;
#include "Solution.cpp"

int main() {
    ifstream file("test_cases.txt");

    if (!file.is_open()) {
        cout << "Failed to open test_cases.txt";
        return 1;
    }

    ProductOfNumbers obj;

    string operation;
    int testCase = 1;

    while (file >> operation) {

        if (operation == "add") {
            int num;
            file >> num;

            obj.add(num);

            cout << "Operation " << testCase << ": add(" << num << ")\n";
            cout << "Status: PASS\n";
        }

        else if (operation == "getProduct") {
            int k, expected;
            file >> k >> expected;

            int res = obj.getProduct(k);

            cout << "Operation " << testCase << ": getProduct(" << k << ")\n";

            if (res == expected) {
                cout << "Status: PASS\n";
            }
            else {
                cout << "Status: FAIL\n";
            }

            cout << "Expected Result: " << expected;
            cout << "\nActual Result: " << res;
            cout << "\n______________________________\n";
        }

        testCase++;
    }

    file.close();
    return 0;
}