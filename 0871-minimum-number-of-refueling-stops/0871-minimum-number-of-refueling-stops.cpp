
class Solution {
public:
    int minRefuelStops(int t, int s, vector<vector<int>>& vs) {
        priority_queue<int> pq;
        int n = vs.size();
        int i = 0, ans = 0;

        while (s < t) {
            while (i < n && vs[i][0] <= s) {
                pq.push(vs[i][1]);
                i++;
            }

            if (pq.empty()) {
                return -1;
            }

            s += pq.top();
            pq.pop();
            ans++;
        }

        return ans;
    }
};
