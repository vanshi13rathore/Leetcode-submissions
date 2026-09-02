class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0, even = 0;

        for (int x : nums1) {
            if (x & 1)
                odd++;
            else
                even++;
        }

        // Already uniform
        if (odd == 0 || even == 0)
            return true;

        // If both parities exist, every element can be made odd
        return true;
    }
};