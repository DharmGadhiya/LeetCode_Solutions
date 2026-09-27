class Solution {
public:
    int myAtoi(string s) {
        string ss;
        bool b = false , sp = false;
        int dh = 0;
        for (auto el : s) {
            if (isdigit(el)) {
                ss += el;
                b = true;
            } else {
                if (b) {
                    break;
                }
                if (el == ' ') {
                    continue;
                } else if (el == '-' || el == '+') {
                    b = true;
                    if (dh != 0) {
                        break;
                    }
                    if (el == '-') {
                        dh = -1;
                    } else {
                        dh = 1;
                    }
                } else {
                    break;
                }
            }
        }

        long long ans = 0, nn = (int)ss.size();
        for (int i = 0; i < nn; i++) {
            ans *= 10;
            ans += (ss[i] - '0');
            if (ans > INT_MAX) {
                ans = INT_MAX;
                if (dh == -1) {
                    ans = INT_MAX + 1ll;
                    ans *= (-1);
                }
                return ans;
            }
        }
        if (dh == -1) {
            ans *= (-1);
        }
        return ans;
    }
};