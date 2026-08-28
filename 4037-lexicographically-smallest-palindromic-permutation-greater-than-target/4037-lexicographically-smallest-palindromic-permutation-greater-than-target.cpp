class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int half = n / 2;

        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0, mid = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = i;
            }
        }

        if (odd > 1)
            return "";

        auto build = [&](string left) {
            string res = left;

            if (n % 2)
                res += char('a' + mid);

            string rev = left;
            reverse(rev.begin(), rev.end());
            res += rev;

            return res;
        };

        // Try to construct the smallest possible first half
        // that is >= target's first half.
        string t = target.substr(0, half);

        for (int start = half; start >= 0; start--) {
            vector<int> rem = cnt;
            string left = "";
            bool ok = true;

            // Keep prefix before 'start'
            for (int i = 0; i < start; i++) {
                int x = t[i] - 'a';

                if (rem[x] < 2) {
                    ok = false;
                    break;
                }

                rem[x] -= 2;
                left += t[i];
            }

            if (!ok)
                continue;

            // Try a character greater than target[start]
            if (start < half) {
                for (int c = t[start] - 'a' + 1; c < 26; c++) {
                    if (rem[c] >= 2) {
                        string cur = left + char('a' + c);
                        rem[c] -= 2;

                        for (int x = 0; x < 26; x++)
                            cur += string(rem[x] / 2, char('a' + x));

                        string ans = build(cur);

                        if (ans > target)
                            return ans;
                    }
                }
            } else {
                // Exact target half
                string cur = left;

                for (int x = 0; x < 26; x++)
                    cur += string(rem[x] / 2, char('a' + x));

                string ans = build(cur);

                if (ans > target)
                    return ans;
            }
        }

        return "";
    }
};