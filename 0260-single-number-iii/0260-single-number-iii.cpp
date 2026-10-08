class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int xorAll = 0;

        for(int num : nums) {
            xorAll ^= num;
        }

        unsigned int mask = (unsigned int)xorAll &
                            (-(unsigned int)xorAll);

        int a = 0;
        int b = 0;

        for(int num : nums) {
            if((unsigned int)num & mask) {
                a ^= num;
            }
            else{
                b ^= num;
            }
        }
        return {a, b};
    }
};