class Solution {
public:
    string removeOuterParentheses(string s) {
        long long int c = 0, d = 0;
        string ans;

        for (long long int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                c++;
            } else {
                c--;
            }

            if (c == 0) {
                ans += string(s.begin() + d + 1, s.begin() + i);
                d = i + 1;
            }
        }

        return ans;
    }
};
