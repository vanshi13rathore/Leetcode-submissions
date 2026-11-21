class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int low = 0;
        int len = 0;

        unordered_map<char, int> f;

        for(int high=0; high<n; high++) {
            f[s[high]]++;

            while(f[s[high]] > 1) {
                char ch = s[low];
                f[ch]--;

                if(f[ch] == 0) {
                    f.erase(ch);
                }
                low++;
            }
            len = max(len , high-low+1);
        }
        return len;
    }
};