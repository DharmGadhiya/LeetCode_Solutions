class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](vector<int>& v1, vector<int>& v2) {
            return v1[0] < v2[0];
        });

        map<int, int> mp;
        vector<int> vb(n, 0);

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        auto cmp = [](pair<long long, int> p1, pair<long long, int> p2) {
            if (p1.first == p2.first) {
                return p1.second > p2.second;
            }
            return p1.first > p2.first;
        };

        priority_queue<pair<long long, int>,
            vector<pair<long long, int>>, decltype(cmp)> pq1(cmp);

        for (int i = 0; i < v.size(); i++) {
            long long st = v[i][0];
            long long en = v[i][1];
            long long dur = en - st;

            while (!pq1.empty() && pq1.top().first <= st) {
                auto pp = pq1.top();
                pq1.pop();

                pq.pop();
                vb[pp.second] = 0;
            }

            int rm = -1;

            for (int j = 0; j < n; j++) {
                if (vb[j] == 0) {
                    rm = j;
                    break;
                }
            }

            if (rm != -1) {
                vb[rm] = 1;
                pq.push(en);
                pq1.push({en, rm});
                mp[rm]++;
            }
            else {
                auto pp = pq1.top();
                pq1.pop();
                pq.pop();

                long long newEnd = pp.first + dur;

                pq.push(newEnd);
                pq1.push({newEnd, pp.second});
                mp[pp.second]++;
            }
        }

        int ans = 0, c = 0;

        for (auto &el : mp) {
            if (ans < el.second) {
                ans = el.second;
                c = el.first;
            }
        }

        return c;
    }
};