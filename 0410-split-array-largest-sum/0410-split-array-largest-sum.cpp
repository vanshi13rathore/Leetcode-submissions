class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();

        long long low = *max_element(nums.begin(),nums.end());
        long long high = accumulate(nums.begin(),nums.end(),0LL);

        while(low <= high) {
            long long mid = low + (high - low ) / 2;

            int subarrays = 1;
            long long sum = 0;


            for(int x : nums) {
                if(sum + x <= mid ) {
                    sum += x;
                }
                else{
                    subarrays++;
                    sum = x;
                }
            }
            if(subarrays <= k) {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
        
    }
};