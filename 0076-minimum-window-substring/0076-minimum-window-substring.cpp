class Solution {
public:
    bool valid(vector<int>& f, vector<int>& h) {
        for(int i=0; i<128; i++) {
            if(f[i] < h[i]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        int low = 0, start = 0, minlen = INT_MAX;

        vector<int> f(128,0);
        vector<int> h(128,0);

        for(int i=0; i<n; i++) {
            h[t[i]]++;

        }
        for(int high=0; high<m; high++) {
            f[s[high]]++;

            while(valid(f,h)) {
                if(high-low+1 < minlen) {
                    minlen = high-low+1;
                    start = low;
                }
                f[s[low]]--;
                low++;
            }
        }
        
        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    }
};