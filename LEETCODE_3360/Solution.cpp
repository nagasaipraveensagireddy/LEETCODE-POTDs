class Solution {
public:
    bool canAliceWin(int n) {
        bool alice = true;
        int neg = 10;
        while(n >= neg){
            n -= neg;
            neg--;
            alice = !alice;
        }
        return !alice;
    }
};