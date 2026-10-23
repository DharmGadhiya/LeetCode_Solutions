class Solution {
public:
    void dh(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto el : adj[node]) {
            if (!vis[el]) {
                dh(el, adj, vis);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& ma) {
        int n = ma.size();
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ma[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans =0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                
                dh(i, adj, vis);
                ans++;
            }
        }
        return ans;
    }
};