class Solution {
public:
    int shipWithinDays(vector<int>& v, int d) {
        int l = 1, r = 1e9, ans = 1e9;
        while (l <= r) {
            int m = l + (r - l) / 2;
            long long s = 0, c = 0;
            for (auto el : v) {
                s += el;
                if(el > m){
                    c = 1e9;
                    break;
                }
                if (s > m) {
                    c++;
                    s = el;
                }
            }

            c++;

            if (c <= d) {
                r = m - 1;
                ans = min(ans, m);
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};