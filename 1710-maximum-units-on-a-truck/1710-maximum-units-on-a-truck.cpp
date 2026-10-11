class Solution {
public:
    int maximumUnits(vector<vector<int>>& v, int k) {
        sort(v.begin(), v.end(),
             [](vector<int>& v1, vector<int>& v2) { return v1[1] > v2[1]; });
        int ans = 0, i = 0, n = v.size();
        while (i < n && k != 0) {
            if (k >= v[i][0]) {
                k -= v[i][0];
                ans += (v[i][0] * v[i][1]);
            } else {
               
                ans += (v[i][1] * k);
                 k = 0;
            }
            i++;
        }
        return ans;
    }
};