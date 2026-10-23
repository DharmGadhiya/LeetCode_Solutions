class Solution {
public:
    bool dh(int i, vector<int>& c, int pre, vector<int>& vv,
            vector<vector<int>>& adj) {
        vv[i] = 1;
        if (pre == 11) {
            c[i] = 12;
        } else {
            c[i] = 11;
        }
        for (auto el : adj[i]) {
            if (vv[el] == 0) {
              if(!  dh(el, c, c[i], vv, adj)){
                return false;
              }
            }
            else if(vv[i] == 1 && c[el] == c[i]){
                return false;

            }
        }
       return true; 
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vv(n, 0);
        vector<int> c(n, -1);
        for (int i = 0; i < n; i++) {
            if (!vv[i]) {
                if (!dh(i, c, 11, vv, adj)) {
                    return false;
                }
            }
        }
        return true;
    }
};