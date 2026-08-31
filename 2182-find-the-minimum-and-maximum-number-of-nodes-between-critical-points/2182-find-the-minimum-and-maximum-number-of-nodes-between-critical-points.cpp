class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int pos = 1;
        int prev = head->val;
        head = head->next;

        int first = -1;
        int last = -1;
        int minDist = INT_MAX;

        while (head && head->next) {
            int cur = head->val;
            int next = head->next->val;

            // Check if current node is a critical point
            if ((cur > prev && cur > next) ||
                (cur < prev && cur < next)) {

                if (first == -1) {
                    first = pos;
                }

                if (last != -1) {
                    minDist = min(minDist, pos - last);
                }

                last = pos;
            }

            prev = cur;
            head = head->next;
            pos++;
        }

        // Fewer than 2 critical points
        if (first == -1 || first == last)
            return {-1, -1};

        int maxDist = last - first;

        return {minDist, maxDist};
    }
};