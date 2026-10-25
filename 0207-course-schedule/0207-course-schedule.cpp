class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& vp) {
        vector<vector<int>> adj(n);
        vector<int> in(n, 0);
        for (auto el : vp) {
            in[el[0]]++;
            adj[el[1]].push_back(el[0]);
        }
        queue<int> q;
        int i = 0;
        for (auto el : in) {
            if (el == 0) {
                q.push(i);
            }
            i++;
        }

        int ans = 0;
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            ans++;

            for(auto el : adj[p]){
                in[el]--;
                if(in[el] == 0){
                    q.push(el);
                }
            }
        }

        return ans == n;
    }
};