class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1'000'000'007;
        vector<int> bitcount(32,0) ;
        
        for(int num : nums) {
            for(int bit = 0; bit < 32; bit++) {
                if(num &(1LL << bit)) {
                    bitcount[bit]++;
                }
            }
        }

        long long ans = 0;

        for(int i=0; i<k; i++) {
            long long current = 0;

            for(int bit = 0; bit < 32; bit++) {
                if(bitcount[bit] > 0) {
                    current |= (1LL << bit);
                    bitcount[bit]--;
                }
            }

            ans = (ans + current * current ) % MOD;
        }
        return (int) ans;
    }
};