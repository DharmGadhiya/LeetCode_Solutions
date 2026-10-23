class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26, 0);

        for (char c : letters) {
            cnt[c - 'a']++;
        }

        int n = words.size();
        int ans = 0;

        function<void(int, int)> dfs = [&](int i, int sum) {
            if (i == n) {
                ans = max(ans, sum);
                return;
            }

            dfs(i + 1, sum);

            vector<int> used(26, 0);
            int s = 0;
            bool ok = true;

            for (char c : words[i]) {
                int x = c - 'a';
                used[x]++;
                s += score[x];

                if (used[x] > cnt[x]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                for (int j = 0; j < 26; j++) {
                    cnt[j] -= used[j];
                }

                dfs(i + 1, sum + s);

                for (int j = 0; j < 26; j++) {
                    cnt[j] += used[j];
                }
            }
        };

        dfs(0, 0);
        return ans;
    }
};