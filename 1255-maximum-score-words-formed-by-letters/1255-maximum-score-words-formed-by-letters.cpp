class Solution {
public:
    vector<int> total = vector<int>(26, 0);
    int ans = 0;
    int n;

    void calcScore(int i, vector<string>& words, vector<int>& score,int currScore) {
        if (i >= n) {

            ans = max(ans, currScore);
            return;
        }
        // choice 1: SKIP the current word
        calcScore(i + 1, words, score, currScore);

        // choice 2: TAKE the current word if possible
        string currWord = words[i];
        vector<int> required(26, 0);
        int wordScore = 0;
        bool canTake = true;

        // check the requirements of the current word
        for (char c : currWord) {
            required[c - 'a']++;
            wordScore += score[c - 'a'];
        }

        // check whether we can fulfill these requirements
        for (int i = 0; i < 26; i++) {
            if (required[i] > total[i]) {
                canTake = false;
            }
        }
        // if we can, then we will take this word
        if (canTake) {
            for (int i = 0; i < 26; i++) {
                total[i] -= required[i];
            }
            // took the word
            calcScore(i + 1, words, score, currScore + wordScore);

            // backtrack to the previous state
            for (int j = 0; j < 26; j++) {
                total[j] += required[j];
            }
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        n = words.size();
        total.assign(26, 0);
        ans = 0;
        for (char& c : letters) {
            total[c - 'a']++; // this is the total cnt of chars available
        }

        calcScore(0, words, score, 0); // i, vec,vec, currScore
        return ans;
    }
};