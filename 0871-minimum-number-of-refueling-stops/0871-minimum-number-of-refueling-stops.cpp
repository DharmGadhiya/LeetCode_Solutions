class Solution {
public:
    int minRefuelStops(int t, int s, vector<vector<int>>& vs) {
        int rch = s , n=vs.size();
        priority_queue<int> pq;
        int i = 0 , ans = 0;
        while(t>s){
            while(i < n && vs[i][0] <= s){
                pq.push(vs[i][1]);
                i++;
            }

            if(pq.empty()){
                return -1;
            }

            s+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};