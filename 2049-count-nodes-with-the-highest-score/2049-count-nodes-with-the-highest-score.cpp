class Solution {
public:
    vector<vector<int>> tree;
    vector<int> sz;
    long long mx = 0;
    int ans = 0, n;

    int dfs(int u) {
        sz[u] = 1;

        for (int v : tree[u]) {
            sz[u] += dfs(v);
        }

        return sz[u];
    }

    void solve(int u) {
        long long score = 1;
        int rem = n - sz[u];

        if (rem > 0)
            score *= rem;

        for (int v : tree[u]) {
            score *= sz[v];
        }

        if (score > mx) {
            mx = score;
            ans = 1;
        } 
        else if (score == mx) {
            ans++;
        }

        for (int v : tree[u]) {
            solve(v);
        }
    }

    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        tree.assign(n, {});
        sz.assign(n, 0);
        mx = 0;
        ans = 0;

        for (int i = 1; i < n; i++) {
            tree[parents[i]].push_back(i);
        }

        dfs(0);
        solve(0);

        return ans;
    }
};