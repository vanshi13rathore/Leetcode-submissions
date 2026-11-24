class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int pos = n-1;
        
        vector<int> res(n,0);

        while(low <= high) {
            int negative = nums[low] * nums[low];
            int positive = nums[high]* nums[high];

            if(negative > positive) {
                res[pos] = negative;
                low++;
            }
            else{
                res[pos] = positive;
                high--;
            }
            pos--;
        }
        return res;
    }
};