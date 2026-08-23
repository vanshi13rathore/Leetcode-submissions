class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int left = 0, right = 0;
        int qLeft = 0, qRight = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                qLeft++;
            else
                left += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                qRight++;
            else
                right += num[i] - '0';
        }

        // Different number of '?' on each side
        if ((qLeft + qRight) % 2)
            return true;

        int diff = left - right;

        // Alice wins if the difference cannot be balanced.
        return diff != (qRight - qLeft) * 9 / 2;
    }
};