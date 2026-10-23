class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;

    int dfs(int u) {
        vis[u] = 1;
        int cnt = 1;

        for (int v : adj[u]) {
            if (!vis[v]) {
                cnt += dfs(v);
            }
        }

        return cnt;
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        adj.assign(n, {});
        vis.assign(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int x : restricted) {
            vis[x] = 1;
        }

        return dfs(0);
    }
};