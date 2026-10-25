class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> bp(n, -1);

        for (int i = 0; i < n; i++) {
            if (bp[i] != -1) {
                continue;
            }
            bp[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int p = q.front();
                q.pop();

                for (auto el : adj[p]) {
                    if (bp[el] == -1) {
                        bp[el] = 1 - bp[p];
                        q.push(el);
                    } else if (bp[el] == bp[p]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};