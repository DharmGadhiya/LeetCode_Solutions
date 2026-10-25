
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int cnt[26] = {0};

        for (char c : letters)
            cnt[c - 'a']++;

        return solve(0, words, cnt, score);
    }

    int solve(int i, vector<string>& words, int cnt[], vector<int>& score) {
        if (i == words.size())
            return 0;

        // Option 1: Skip this word
        int ans = solve(i + 1, words, cnt, score);

        // Option 2: Take this word, if possible
        int val = 0;
        bool ok = true;

        for (char c : words[i]) {
            cnt[c - 'a']--;
            val += score[c - 'a'];

            if (cnt[c - 'a'] < 0)
                ok = false;
        }

        if (ok)
            ans = max(ans, val + solve(i + 1, words, cnt, score));

        // Restore letters for other choices
        for (char c : words[i])
            cnt[c - 'a']++;

        return ans;
    }
};
