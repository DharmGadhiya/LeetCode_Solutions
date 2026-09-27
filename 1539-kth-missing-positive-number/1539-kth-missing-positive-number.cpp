class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        int l = 0, r = v.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int c = v[m] - m - 1;
            if (c < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if(r < 0){
            return k;
        }
        int cc = v[r] - r - 1;
        k -= cc;
        int ans = v[r] + k;
        return ans;
    }
};