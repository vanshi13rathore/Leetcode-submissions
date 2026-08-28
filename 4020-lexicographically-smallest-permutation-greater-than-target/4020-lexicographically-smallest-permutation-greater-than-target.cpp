class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        string ans = "";

        for (int i = 0; i < n; i++) {
            // Try to keep target[i] exactly.
            int x = target[i] - 'a';

            if (cnt[x] > 0) {
                cnt[x]--;
                ans += target[i];
                continue;
            }

            // Can't match target[i].
            // Find the smallest character greater than target[i].
            int bigger = -1;

            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger != -1) {
                ans += char('a' + bigger);
                cnt[bigger]--;

                // Once greater, append everything smallest first.
                for (int c = 0; c < 26; c++)
                    ans += string(cnt[c], char('a' + c));

                return ans;
            }

            // We cannot continue matching target.
            // We need to backtrack and make an earlier position bigger.
            break;
        }

        // target itself was constructible, but it is not strictly greater.
        // Backtrack from the right.
        cnt.assign(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        for (int i = n - 1; i >= 0; i--) {
            // Put target[0..i-1] into the permutation.
            vector<int> rem = cnt;
            bool ok = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (rem[x] == 0) {
                    ok = false;
                    break;
                }

                rem[x]--;
            }

            if (!ok)
                continue;

            // At position i, choose the smallest character > target[i].
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (rem[c] > 0) {
                    string res = target.substr(0, i);
                    res += char('a' + c);
                    rem[c]--;

                    for (int d = 0; d < 26; d++)
                        res += string(rem[d], char('a' + d));

                    return res;
                }
            }
        }

        return "";
    }
};