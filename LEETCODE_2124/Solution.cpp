class Solution {
public:
    bool checkString(string s) {
        bool EncounteredB = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a' && EncounteredB) return false;
            if(s[i] == 'b') EncounteredB = true;
        }
        return true;
    }
};