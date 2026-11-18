class Solution {
public:
    int minChanges(string s) {
        string temp = "";
        int res = 0;
        for(int i = 1; i < s.size(); i += 2){
            if(s[i - 1] != s[i]) res++;
        }
        return res;
    }
};