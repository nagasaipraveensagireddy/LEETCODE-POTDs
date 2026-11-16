class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string temp;
            int t = 0;
            for(int i = 1; i <= s.size(); i++){
                int num = s[i - 1] - '0';
                if(i % k == 0){
                    t += num;
                    temp += to_string(t);
                    t = 0;
                }
                else t += num;
            }
            if(s.size() % k) temp += to_string(t);
            s = temp;
        }
        return s;
    }
};