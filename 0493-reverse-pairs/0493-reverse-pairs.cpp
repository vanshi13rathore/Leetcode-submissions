class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int i = low, j = mid + 1;

        while(i <= mid && j <= high) {
            if(nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while(i <= mid)
            temp.push_back(nums[i++]);

        while(j <= high)
            temp.push_back(nums[j++]);

        for(int k = low; k <= high; k++)
            nums[k] = temp[k - low];
    }

    long long mergeSort(vector<int>& nums, int low, int high) {
        if(low >= high)
            return 0;

        int mid = low + (high - low) / 2;
        long long cnt = 0;

        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);

        int j = mid + 1;

        for(int i = low; i <= mid; i++) {
            while(j <= high && (long long)nums[i] > 2LL * nums[j])
                j++;

            cnt += j - (mid + 1);
        }

        merge(nums, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};