class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool odd = false, even = false;

        for (int x : nums1) {
            if (x & 1) odd = true;
            else even = true;
        }

        if (!odd || !even) return true;

        return *min_element(nums1.begin(), nums1.end()) & 1;
    }
};