class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& v) {
        vector<int> in(n, 0);
        vector<vector<int>> adj(n);
        for (auto el : v) {
            adj[el[0]].push_back(el[1]);
            in[el[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int c = q.front();
            q.pop();
            for (auto el : adj[c]) {
                if (in[el] == 1) {
                    q.push(el);
                }
                in[el]--;
            }
            ans.push_back(c);
        }
        return (ans.size() == n);
    }
};