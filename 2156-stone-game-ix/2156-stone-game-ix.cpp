class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for (int x : stones)
            cnt[x % 3]++;

        auto check = [&](int one, int two, int zero) {
            if (one == 0)
                return false;

            // Alice takes a remainder-1 stone first.
            one--;

            int pairs = min(one, two);
            int len = 1 + 2 * pairs + zero;

            one -= pairs;
            two -= pairs;

            if (one > 0) {
                len++;
                one--;
            }

            return len % 2 == 1 && (one + two > 0);
        };

        // Alice can start with either remainder 1 or remainder 2.
        return check(cnt[1], cnt[2], cnt[0]) ||
               check(cnt[2], cnt[1], cnt[0]);
    }
};