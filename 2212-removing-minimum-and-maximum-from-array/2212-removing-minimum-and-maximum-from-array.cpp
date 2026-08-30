class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = min_element(nums.begin(), nums.end()) - nums.begin();
        int mx = max_element(nums.begin(), nums.end()) - nums.begin();

        int a = min(mn, mx);
        int b = max(mn, mx);

        // 1. Remove both from the front
        int front = b + 1;

        // 2. Remove both from the back
        int back = n - a;

        // 3. Remove a from front and b from back
        int both = (a + 1) + (n - b);

        return min({front, back, both});
    }
};