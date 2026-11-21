class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();
        int low = 0;
        int len = INT_MIN;
        int k = 2;

        unordered_map<int, int> f;

        for(int high=0; high<n; high++) {
            f[fruits[high]]++;

            while(f.size() > k) {
                int num = fruits[low];
                f[num]--;

                if(f[num] == 0) {
                    f.erase(num);

                }
                low++;
            }

            
            len = max(len, high-low+1);
            
        }
        return len == INT_MIN ? -1 : len;
    }
};